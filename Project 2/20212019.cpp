#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mysql.h"
#include <cstring>
#include <stdlib.h>
#include <string.h>
#include <sql.h>
#include <sqlext.h>

#pragma comment(lib, "libmysql.lib")

const char *host = "localhost";
const char *user = "root";
const char *pw = "minwoo2246*";
const char *db = "project";

#define MAX_DATA 100

SQLHENV env;
SQLHDBC dbc;
SQLHSTMT stmt;

void executeSQLQuery(char *query)
{
	SQLRETURN ret;
	ret = SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
	if (!SQL_SUCCEEDED(ret))
	{
		printf("Error allocating statement handle\n");
		return;
	}

	ret = SQLExecDirect(stmt, (SQLCHAR *)query, SQL_NTS);
	if (!SQL_SUCCEEDED(ret))
	{
		printf("Error executing query\n");
		SQLFreeHandle(SQL_HANDLE_STMT, stmt);
		return;
	}

	SQLFreeHandle(SQL_HANDLE_STMT, stmt);
}

void printQueryResults(char *query)
{
	SQLRETURN ret;
	SQLSMALLINT columns;
	ret = SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
	if (!SQL_SUCCEEDED(ret))
	{
		printf("Error allocating statement handle\n");
		return;
	}

	ret = SQLExecDirect(stmt, (SQLCHAR *)query, SQL_NTS);
	if (!SQL_SUCCEEDED(ret))
	{
		printf("Error executing query\n");
		SQLFreeHandle(SQL_HANDLE_STMT, stmt);
		return;
	}

	SQLNumResultCols(stmt, &columns);
	while (SQL_SUCCEEDED(ret = SQLFetch(stmt)))
	{
		for (int i = 1; i <= columns; i++)
		{
			SQLCHAR data[MAX_DATA];
			SQLLEN len;
			ret = SQLGetData(stmt, i, SQL_C_CHAR, data, MAX_DATA, &len);
			if (SQL_SUCCEEDED(ret))
				printf("%s ", data);
		}
		printf("\n");
	}

	SQLFreeHandle(SQL_HANDLE_STMT, stmt);
}

int main(void)
{

	MYSQL *connection = NULL;
	MYSQL conn;
	MYSQL_RES *sql_result;
	MYSQL_ROW sql_row;

	if (mysql_init(&conn) == NULL)
		printf("mysql_init() error!");

	connection = mysql_real_connect(&conn, host, user, pw, db, 3306, (const char *)NULL, 0);
	if (connection == NULL)
	{
		printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
		return 1;
	}

	else
	{
		printf("Connection Succeed");

		if (mysql_select_db(&conn, db))
		{
			printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
			return 1;
		}

		FILE *fp;
		fp = fopen("20212019_1.txt", "r");
		while (!feof(fp))
		{
			char data[1024];
			if (!fgets(data, 1024, fp))
				break;
			mysql_query(connection, data);
		}
		fclose(fp);

		while (1)
		{
			printf("\n\n------- SELECT QUERY TYPES -------\n\n");
			printf("\t1. TYPE 1.\n");
			printf("\t2. TYPE 2.\n");
			printf("\t3. TYPE 3.\n");
			printf("\t4. TYPE 4.\n");
			printf("\t5. TYPE 5.\n");
			printf("\t6. TYPE 6.\n");
			printf("\t7. TYPE 7.\n");
			printf("\t0. QUIT.\n");
			printf("\n----------------------------------\n");

			int command = 0;
			printf(">	Please select a query type : ");
			scanf("%d", &command);

			if (command == 0)
				break;
			else if (command == 1)
			{
				while (1)
				{
					printf("\n\n----- Subtypes in TYPE 1 -----\n");
					printf("\t1. TYPE 1-1.\n");

					char query[] = "SELECT address FROM Property WHERE address LIKE '%Mapo%';";
					printQueryResults(query);

					int subcmd = 0;
					printf(">	Please select a subquery type : ");
					scanf("%d", &subcmd);

					if (subcmd == 0)
						break;
					else if (subcmd == 1)
					{
						char query[] = "SELECT address FROM Property WHERE address LIKE '%Mapo%' AND listing_price BETWEEN 1000000000 AND 1500000000;";
						printQueryResults(query);
					}
					else
					{
						printf("Invalid choice\n");
					}
				}
			}
			else if (command == 2)
			{
				while (1)
				{
					printf("\n\n----- Subtypes in TYPE 2 -----\n");
					printf("\t1. TYPE 2-1.\n");

					char query[] = "SELECT address FROM Property WHERE school_district = '8';";
					printQueryResults(query);

					int subcmd = 0;
					printf(">	Please select a subquery type : ");
					scanf("%d", &subcmd);

					if (subcmd == 0)
						break;
					else if (subcmd == 1)
					{
						char query[] = "SELECT address FROM Property WHERE school_district = '8' AND bedroom_count >= 4 AND bathroom_count = 2;";
						printQueryResults(query);
					}
					else
					{
						printf("Invalid choice\n");
					}
				}
			}
			else if (command == 3)
			{
				while (1)
				{
					printf("\n\n----- Subtypes in TYPE 3 -----\n");
					printf("\t1. TYPE 3-1.\n");
					printf("\t1. TYPE 3-2.\n");

					char query[] = "SELECT a.name, SUM(t.sale_price) AS total_sales FROM Agent a JOIN Transaction t ON a.agent_id = t.Selling_agent_id WHERE YEAR(t.sale_date) = 2022 GROUP BY a.agent_id ORDER BY total_sales DESC LIMIT 1;";
					printQueryResults(query);

					int subcmd = 0;
					printf(">	Please select a subquery type : ");
					scanf("%d", &subcmd);

					if (subcmd == 0)
						break;
					else if (subcmd == 1)
					{
						int k;
						printf("Enter value of K: ");
						scanf("%d", &k);
						char query[MAX_DATA];
						sprintf(query, "SELECT a.name, SUM(t.sale_price) AS total_sales FROM Agent a JOIN Transaction t ON a.agent_id = t.Selling_agent_id WHERE YEAR(t.sale_date) = 2023 GROUP BY a.agent_id ORDER BY total_sales DESC LIMIT %d;", k);
						printQueryResults(query);
					}
					else if (subcmd == 2)
					{
						char query[] = "SELECT a.name, SUM(t.sale_price) AS total_sales FROM Agent a JOIN Transaction t ON a.agent_id = t.Selling_agent_id WHERE YEAR(t.sale_date) = 2021 GROUP BY a.agent_id ORDER BY total_sales ASC LIMIT (SELECT 0.1 * COUNT(DISTINCT Selling_agent_id) FROM Transaction WHERE YEAR(sale_date) = 2021);";
						printQueryResults(query);
					}
					else
					{
						printf("Invalid choice\n");
					}
				}
			}
			else if (command == 4)
			{
				while (1)
				{
					printf("\n\n----- Subtypes in TYPE 4 -----\n");
					printf("\t1. TYPE 4-1.\n");
					printf("\t1. TYPE 4-2.\n");

					char query[] = "SELECT a.name, AVG(t.sale_price) AS avg_price, AVG(DATEDIFF(t.sale_date, p.listed_date)) AS avg_days_on_market FROM Agent a JOIN Transaction t ON a.agent_id = t.Selling_agent_id JOIN Property p ON t.PropertyID = p.property_id WHERE YEAR(t.sale_date) = 2022 GROUP BY a.agent_id;";
					printQueryResults(query);

					int subcmd = 0;
					printf(">	Please select a subquery type : ");
					scanf("%d", &subcmd);

					if (subcmd == 0)
						break;
					else if (subcmd == 1)
					{
						char query[] = "SELECT a.name, MAX(t.sale_price) AS max_sale_price FROM Agent a JOIN Transaction t ON a.agent_id = t.Selling_agent_id WHERE YEAR(t.sale_date) = 2023 GROUP BY a.agent_id;";
						printQueryResults(query);
					}
					else if (subcmd == 2)
					{
						char query[] = "SELECT a.name, MAX(DATEDIFF(t.sale_date, p.listed_date)) AS max_days_on_market FROM Agent a JOIN Transaction t ON a.agent_id = t.Selling_agent_id JOIN Property p ON t.PropertyID = p.property_id GROUP BY a.agent_id;";
						printQueryResults(query);
					}
					else
					{
						printf("Invalid choice\n");
					}
				}
			}
			else if (command == 5)
			{
				printf("\nShowing photos of the most expensive properties by type:\n");
				char query[] = "SELECT Image_url FROM Property WHERE property_type = 'studio' ORDER BY listing_price DESC LIMIT 1;";
				printf("Most expensive studio: ");
				printQueryResults(query);

				query[51] = 'o';
				query[52] = 'n';
				query[53] = 'e';
				query[54] = '_';
				printf("Most expensive one-bedroom: ");
				printQueryResults(query);

				query[51] = 'm';
				query[52] = 'u';
				query[53] = 'l';
				query[54] = 't';
				query[55] = 'i';
				query[56] = '_';
				printf("Most expensive multi-bedroom: ");
				printQueryResults(query);

				query[51] = 'd';
				query[52] = 'e';
				query[53] = 't';
				query[54] = 'a';
				query[55] = 'c';
				query[56] = 'h';
				query[57] = 'e';
				query[58] = 'd';
				printf("Most expensive detached house: ");
				printQueryResults(query);
			}
			else if (command == 6)
			{
				printf("\nEnter transaction details to record a sale:\n");
				int transaction_id, property_id, buyer_id, selling_agent_id, buying_agent_id;
				double sale_price;
				char sale_date[11];
				printf("Transaction ID: ");
				scanf("%d", &transaction_id);
				printf("Property ID: ");
				scanf("%d", &property_id);
				printf("Buyer ID: ");
				scanf("%d", &buyer_id);
				printf("Selling Agent ID: ");
				scanf("%d", &selling_agent_id);
				printf("Buying Agent ID (0 if none): ");
				scanf("%d", &buying_agent_id);
				printf("Sale Price: ");
				scanf("%lf", &sale_price);
				printf("Sale Date (YYYY-MM-DD): ");
				scanf("%s", sale_date);

				char query[MAX_DATA];
				sprintf(query, "INSERT INTO Transaction (transaction_id, PropertyID, buyer_id, Selling_agent_id, buying_agent_id, sale_price, sale_date) VALUES (%d, %d, %d, %d, %d, %.2f, '%s');", transaction_id, property_id, buyer_id, selling_agent_id, buying_agent_id, sale_price, sale_date);
				executeSQLQuery(query);

				sprintf(query, "INSERT INTO Buy (buyer_id, transaction_id) VALUES (%d, %d);", buyer_id, transaction_id);
				executeSQLQuery(query);
				printf("Transaction recorded successfully\n");
			}
			else if (command == 7)
			{
				printf("\nEnter details of the new agent:\n");
				int agent_id;
				char name[51], phone[21];
				printf("Agent ID: ");
				scanf("%d", &agent_id);
				printf("Name: ");
				scanf("%s", name);
				printf("Phone: ");
				scanf("%s", phone);

				char query[MAX_DATA];
				sprintf(query, "INSERT INTO Agent (agent_id, name, phone) VALUES (%d, '%s', '%s');", agent_id, name, phone);
				executeSQLQuery(query);
				printf("Agent added successfully\n");
			}
			else if (command == 0)
			{
				break;
			}
			else
			{
				printf("Invalid choice\n");
			}
		}

		FILE *fp2;
		fp2 = fopen("20212019_2.txt", "r");
		while (!feof(fp2))
		{
			char data[1024];
			if (!fgets(data, 1024, fp2))
				break;
			mysql_query(connection, data);
		}
		fclose(fp2);

		printf("Bye");
	}

	return 0;
}