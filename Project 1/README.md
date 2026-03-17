# Project 1: 부동산 거래 DB 모델링

Project 1은 부동산 거래 시스템의 데이터 구조를 **개념/논리 모델링 관점**에서 설계한 과제입니다.  
핵심 목표는 실제 구현 이전에 도메인 객체와 관계를 명확히 정의하고, 이후 Project 2에서 바로 구현 가능한 수준의 스키마 기반을 만드는 것입니다.

## 과제 목표

- 부동산 거래 도메인의 핵심 엔티티 식별
- 엔티티 간 관계(카디널리티/참여 제약) 정의
- 키/속성/관계 구조를 통해 일관된 ER 모델 수립
- 구현 가능한 스키마로 연결 가능한 설계 산출물 생성

## 핵심 산출물

- [E-R diagram.png](./E-R%20diagram.png)
- [E-R Schema.png](./E-R%20Schema.png)
- [20212019.erwin](./20212019.erwin)
- [과제1 보고서.pdf](./과제1%20보고서.pdf)
- [project1(spring2024).pdf](./Specification/project1(spring2024).pdf)
- [Data Modeling Overview.pdf](./Specification/Data%20Modeling%20Overview.pdf)

## 모델링 핵심 포인트

### 주요 엔티티

- `Agent`: 중개인 정보(식별자, 이름, 연락처)
- `Buyer`: 매수자 정보
- `Seller`: 매도자 정보
- `Property`: 매물 정보(주소, 가격, 유형, 침실/욕실 수, 학군, 상장일 등)
- `Transaction`: 거래 정보(거래일, 거래가, 참여자 참조)

### 주요 관계

- `Represent`: 중개인-매물 연결
- `Sell`: 매도자-매물 연결
- `Buy`: 매수자-거래 연결
- `Property`와 `Transaction` 간 거래 대상 연결

## 내가 한 일

- 요구사항 문서를 바탕으로 엔티티/속성 후보를 먼저 정리하고, 중복 속성과 파생 가능 속성을 분리했습니다.
- 식별자(Primary Key)와 참조 키(Foreign Key)를 중심으로 관계 무결성이 유지되도록 모델을 정제했습니다.
- ER Diagram과 ER Schema를 병행 관리하여, 시각적 개념 모델과 구현 지향 구조가 서로 어긋나지 않도록 맞췄습니다.
- 보고서에서 설계 선택 이유(왜 해당 엔티티/관계를 분리했는지)를 문서화해 이후 구현 단계(Project 2)에서 재해석 비용이 없도록 했습니다.

## Project 2로의 연결

Project 1에서 확정한 모델은 Project 2에서 다음과 같이 이어집니다.

- 테이블 생성 DDL로 변환: [../Project 2/20212019_1.txt](../Project%202/20212019_1.txt)
- 물리 스키마 다이어그램 확인: [../Project 2/physical diagram.png](../Project%202/physical%20diagram.png)
- 질의/입력 프로그램 구현: [../Project 2/20212019.cpp](../Project%202/20212019.cpp)

