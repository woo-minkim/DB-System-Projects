# Project 1. Real Estate Transaction DB Modeling

부동산 거래 도메인을 대상으로 **핵심 엔티티, 속성, 관계를 구조화하고 ER 기반 데이터 모델로 설계한 프로젝트**입니다.  
실제 구현 이전 단계에서 도메인 구조를 명확히 정의하고 이후 Project 2에서 물리 스키마와 프로그램 구현으로 이어질 수 있는 설계 기반을 마련했습니다.

## Key Highlights

- 부동산 거래 도메인의 핵심 엔티티 및 관계 정의
- 카디널리티와 참여 제약을 반영한 ER 모델 설계
- PK/FK 기반으로 확장 가능한 논리 스키마 정리
- Project 2의 물리 스키마 구현으로 연결 가능한 모델링 수행

## Tech Stack

- **Modeling Tool**: ERwin
- **Output**: E-R Diagram, E-R Schema, Report Documentation

## Domain Overview

이 프로젝트에서는 부동산 거래 시스템을 구성하는 주요 객체를 식별하고,  
각 객체가 어떤 역할과 관계를 가지는지 데이터 관점에서 구조화했습니다.

### Core Entities

- `Agent` — 중개인 정보
- `Buyer` — 매수자 정보
- `Seller` — 매도자 정보
- `Property` — 매물 정보
- `Transaction` — 거래 정보

### Key Relationships

- `Represent` — 중개인과 매물 간 관계
- `Sell` — 매도자와 매물 간 관계
- `Buy` — 매수자와 거래 간 관계
- `Property` - `Transaction` — 거래 대상 매물 연결

## My Contributions

- 요구사항 문서를 기준으로 엔티티와 속성 후보를 도출하고 도메인 구조를 정리했습니다.
- 중복 속성과 파생 가능 속성을 분리해 모델의 일관성과 확장성을 높였습니다.
- Primary Key와 Foreign Key를 기준으로 관계를 정제해 참조 무결성을 고려한 논리 스키마를 설계했습니다.
- ER Diagram과 ER Schema를 병행 관리하며 개념 모델과 구현 지향 구조가 어긋나지 않도록 정합성을 맞췄습니다.
- 설계 선택 이유를 문서화해 Project 2에서 별도 재해석 없이 물리 스키마 구현으로 이어질 수 있도록 정리했습니다.

## Modeling Focus

이 프로젝트에서 중요하게 본 부분은 다음과 같습니다.

- **도메인 구조 명확화**  
  거래 참여자, 매물, 거래 정보를 역할별로 분리해 데이터 책임 범위를 명확히 정의했습니다.

- **관계 중심 설계**  
  단순 속성 나열보다 엔티티 간 연결 구조와 제약조건을 우선해 모델을 설계했습니다.

- **구현 연계성 확보**  
  추상적인 개념 모델에 머무르지 않고 실제 테이블 구조로 확장 가능한 형태의 스키마를 만들었습니다.

## Deliverables

- [E-R diagram.png](./E-R%20diagram.png) — 개념 모델 다이어그램
- [E-R Schema.png](./E-R%20Schema.png) — 논리 스키마 구조
- [20212019.erwin](./20212019.erwin) — ERwin 원본 파일
- [과제1 보고서.pdf](./과제1%20보고서.pdf) — 설계 보고서
- [project1(spring2024).pdf](./Specification/project1(spring2024).pdf) — 과제 명세
- [Data Modeling Overview.pdf](./Specification/Data%20Modeling%20Overview.pdf) — 참고 문서

## From Project 1 to Project 2

Project 1에서 설계한 모델은 Project 2에서 실제 구현으로 확장했습니다.

- 테이블 생성 DDL: [../Project 2/20212019_1.txt](../Project%202/20212019_1.txt)
- 물리 스키마 다이어그램: [../Project 2/physical diagram.png](../Project%202/physical%20diagram.png)
- 질의/입력 프로그램 구현: [../Project 2/20212019.cpp](../Project%202/20212019.cpp)