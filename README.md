# DB System Projects

부동산 거래 도메인을 대상으로 수행한 데이터베이스 시스템 과제 저장소입니다.  
이 저장소는 설계 중심의 **Project 1**과 구현/질의 중심의 **Project 2**로 구성되어 있으며, 요구사항 분석부터 ER 모델링, 물리 스키마 구현, SQL 질의 실행 프로그램 작성까지의 흐름을 한 번에 확인할 수 있습니다.

## 프로젝트 개요

- 과목 맥락: DB System 수업 과제
- 문제 정의: 부동산 매물/거래/중개인/매수자/매도자 데이터를 관계형 데이터베이스로 설계하고, 실제 질의를 수행 가능한 형태로 구현
- 결과물 형태: 모델링 산출물(ER Diagram, ER Schema, `.erwin`, 보고서)
- 결과물 형태: 물리 구현 산출물(SQL DDL/DML, C++ 기반 MySQL 질의 프로그램, 실행 가이드/보고서)

## 저장소 구조

```text
DB System Projects/
├─ Project 1/
│  ├─ E-R diagram.png
│  ├─ E-R Schema.png
│  ├─ 20212019.erwin
│  ├─ 과제1 보고서.pdf
│  └─ Specification/
└─ Project 2/
   ├─ 20212019.cpp
   ├─ 20212019_1.txt
   ├─ 20212019_2.txt
   ├─ 20212019.erwin
   ├─ physical diagram.png
   ├─ [project2]20212019.pdf
   └─ Specification/
```

## Project 1 → Project 2 연결 흐름

1. **Project 1**에서 도메인 요구사항을 분석하고 핵심 엔티티/관계를 ER 모델로 구조화
2. ER 모델을 바탕으로 키/제약/속성을 포함한 스키마 형태로 정제
3. **Project 2**에서 실제 테이블/관계(DDL)와 샘플 데이터(DML)를 구현
4. C++ 프로그램에서 메뉴 기반 질의(TYPE 1~7)를 통해 조회/집계/삽입 기능 검증

## 내가 수행한 내용

- 요구사항 해석 후 부동산 거래 도메인 핵심 데이터 객체 정의
- ER 다이어그램 및 스키마 설계(엔티티, 관계, 키, 제약 반영)
- MySQL 기준 테이블 생성/관계 연결 SQL 작성
- 샘플 데이터 구성 및 조인/집계 중심 질의 시나리오 구현
- C++ 프로그램에서 사용자 입력 기반 조회/등록 기능 구현
- 보고서 및 다이어그램으로 설계 의도와 결과 문서화

## 빠른 탐색 가이드

1. 전체 흐름 파악: [Project 1 README](./Project%201/README.md) → [Project 2 README](./Project%202/README.md)
2. 설계부터 보기: `Project 1/E-R diagram.png` → `Project 1/E-R Schema.png` → `Project 1/과제1 보고서.pdf`
3. 구현부터 보기: `Project 2/20212019_1.txt`(DDL/DML) → `Project 2/20212019.cpp`(질의 로직) → `Project 2/[project2]20212019.pdf`

## 문서 인덱스

- [Project 1 상세 README](./Project%201/README.md)
- [Project 2 상세 README](./Project%202/README.md)
