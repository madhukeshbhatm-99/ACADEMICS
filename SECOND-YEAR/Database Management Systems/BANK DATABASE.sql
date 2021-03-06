CREATE TABLE BRANCH
(
  BRANCH_NAME VARCHAR2(15),
  BRANCH_CITY VARCHAR2(10),
  ASSETS NUMBER(10,2),
  PRIMARY KEY (BRANCH_NAME)
);

CREATE TABLE ACCOUNT
(
  ACCNO NUMBER(15),
  BRANCH_NAME VARCHAR2(15),
  BALANCE NUMBER(8),
  PRIMARY KEY (ACCNO),
  FOREIGN KEY (BRANCH_NAME) REFERENCES BRANCH(BRANCH_NAME)
);

CREATE TABLE CUSTOMER
(
  CUSTOMER_NAME VARCHAR2(15),
  CUSTOMER_STREET VARCHAR2(15),
  CITY VARCHAR2(10),
  PRIMARY KEY (CUSTOMER_NAME)
);

CREATE TABLE LOAN
(
  LOAN_NUMBER NUMBER(8),
  BRANCH_NAME VARCHAR2(15),
  AMOUNT NUMBER(8,2),
  PRIMARY KEY (LOAN_NUMBER),
  FOREIGN KEY (BRANCH_NAME) REFERENCES BRANCH(BRANCH_NAME)
);

CREATE TABLE DEPOSITER
(
  CUSTOMER_NAME VARCHAR2(15),
  ACCNO NUMBER(15),
  PRIMARY KEY (CUSTOMER_NAME, ACCNO),
  FOREIGN KEY (CUSTOMER_NAME) REFERENCES CUSTOMER(CUSTOMER_NAME), 
  FOREIGN KEY (ACCNO) REFERENCES ACCOUNT(ACCNO)
);

CREATE TABLE BORROWER
(
  CUSTOMER_NAME VARCHAR2(15),
  LOAN_NUMBER NUMBER(8),
  PRIMARY KEY (CUSTOMER_NAME, LOAN_NUMBER),
  FOREIGN KEY (CUSTOMER_NAME) REFERENCES CUSTOMER(CUSTOMER_NAME), 
  FOREIGN KEY (LOAN_NUMBER) REFERENCES LOAN(LOAN_NUMBER)
);

INSERT INTO BRANCH VALUES ('&BRANCH_NAME', '&BRANCH_CITY', &ASSETS);
INSERT INTO BRANCH VALUES ('KORAMANGALA', 'BENGALURU', 1500000);
INSERT INTO BRANCH VALUES ('VIDYANAGAR', 'MYSURU', 150000);
INSERT INTO BRANCH VALUES ('KATEEL', 'MANGALURU', 1000000);
INSERT INTO BRANCH VALUES ('MIRZAPUR', 'YADGIRI', 50000);

INSERT INTO CUSTOMER VALUES ('&CUSTOMER_NAME', '&CUSTOMER_STREET', '&CITY');
INSERT INTO CUSTOMER VALUES ('SRIKANTH PAI', 'CHURCH RD', 'BELTANGADI');
INSERT INTO CUSTOMER VALUES ('KUMARA', 'RATHA BEEDHI', 'K R PETE');
INSERT INTO CUSTOMER VALUES ('VIVEK RAJ', 'DAIRY CIRCLE', 'BLURU CITY');
INSERT INTO CUSTOMER VALUES ('NIJALINGA SWAMY', 'KAVERINAGAR', 'ANEKAL');

INSERT INTO ACCOUNT VALUES (&ACCNO, '&BRANCH_NAME', &BALANCE);
INSERT INTO ACCOUNT VALUES (123123123, 'KORAMANGALA', 180000);
INSERT INTO ACCOUNT VALUES (123456541, 'VIDYANAGAR', 50000);
INSERT INTO ACCOUNT VALUES (147852369, 'KATEEL', 25000);
INSERT INTO ACCOUNT VALUES (135798642, 'MIRZAPUR', 5000);

INSERT INTO LOAN VALUES (&LOAN_NUMBER, '&BRANCH_NAME', &AMOUNT);
INSERT INTO LOAN VALUES (133, 'KORAMANGALA', 18000.00);
INSERT INTO LOAN VALUES (234, 'VIDYANAGAR', 20000.00);
INSERT INTO LOAN VALUES (478, 'KATEEL', 5000.00);
INSERT INTO LOAN VALUES (579, 'MIRZAPUR', 3000.00);

INSERT INTO DEPOSITER VALUES ('&CUSTOMER_NAME', &ACCNO);
INSERT INTO DEPOSITER VALUES ('VIVEK RAJ', 123123123);
INSERT INTO DEPOSITER VALUES ('KUMARA', 123456541);
INSERT INTO DEPOSITER VALUES ('SRIKANTH PAI', 147852369);
INSERT INTO DEPOSITER VALUES ('NASEEB', 135798642);

INSERT INTO BORROWER VALUES ('&CUSTOMER_NAME', &LOAN_NUMBER);
INSERT INTO BORROWER VALUES ('KUMARA', 133);
INSERT INTO BORROWER VALUES ('KUMARA', 234);
INSERT INTO BORROWER VALUES ('SRIKANTH PAI', 478);
INSERT INTO BORROWER VALUES ('NASEEB', 579);

SELECT * FROM BRANCH;

SELECT * FROM CUSTOMER;

SELECT * FROM ACCOUNT;

SELECT * FROM LOAN;

SELECT * FROM DEPOSITER;

SELECT * FROM BORROWER;
