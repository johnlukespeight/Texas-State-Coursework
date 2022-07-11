CREATE DATABASE RetailSales;

CREATE TABLE RETAIL_ORDER ( OrderNumber int,
StoreNumber int,
StoreZIP int,
OrderMonth varchar(20),
OrderYear int,
OrderTotal varchar(20),
PRIMARY KEY(OrderNumber));

CREATE TABLE ORDER_ITEM( OrderNumber int,
SKU varchar(50),
Quantity int,
Price varchar(20),
ExtendedPrice varchar(20),
CONSTRAINT fk_order FOREIGN KEY (OrderNumber)
REFERENCES RETAIL_ORDER(OrderNumber) );

CREATE TABLE SKU_DATA(
SKU varchar(50),
SKU_Description varchar(256),
Department varchar(120),
Buyer varchar(100)
);

CREATE TABLE BUYER (
BuyerName varchar(100),
Department varchar(120),
Position varchar(50),
Supervisor varchar(100)
);

INSERT INTO RETAIL_ORDER(OrderNumber, StoreNumber, StoreZIP, OrderMonth, OrderYear, OrderTotal) VALUES (1000,10, 89098, 'January', 2017, '$440.00');
INSERT INTO RETAIL_ORDER(OrderNumber, StoreNumber, StoreZIP, OrderMonth, OrderYear, OrderTotal) VALUES (2000,20, 12898, 'April', 2018, '$1170.00');
INSERT INTO RETAIL_ORDER(OrderNumber, StoreNumber, StoreZIP, OrderMonth, OrderYear, OrderTotal) VALUES (3000,30, 19998, 'April', 2018, '$1170.00');

INSERT INTO ORDER_ITEM(OrderNumber, SKU, Quantity, Price, ExtendedPrice) VALUES (1000,201000, 1,'$140.00', '$140.00');
INSERT INTO ORDER_ITEM(OrderNumber, SKU, Quantity, Price, ExtendedPrice) VALUES (2000,202000, 4,'$50.00', '$200.00');

INSERT INTO SKU_DATA( SKU, SKU_Description, Department, Buyer ) VALUES (202000, 'Std, Scuba Tank, Yellow','Water Sports', 'Pete Haneson');

INSERT INTO SKU_DATA( SKU, SKU_Description, Department, Buyer ) VALUES (203000, 'Std, Scuba Tank, Orange','Water Sports', 'Cindy Lo');
INSERT INTO SKU_DATA( SKU, SKU_Description, Department, Buyer ) VALUES (201000, 'Half-dome Tent','Camping', 'Cindy Lo');

INSERT INTO BUYER( BuyerName, Department, Position, Supervisor ) VALUES ('Cindy Lo','Purchasing','Buyer 1', 'Pete Haneson');
INSERT INTO BUYER( BuyerName, Department , Position,Supervisor ) VALUES ('Pete Haneson', 'Purchasing','Manager', 'None');
INSERT INTO BUYER( BuyerName, Department, Position, Supervisor ) VALUES ('Pete Haneson','Purchasing','Buyer 2', 'Cindy Lo');
INSERT INTO BUYER( BuyerName, Department , Position,Supervisor ) VALUES ('Cindy Lo', 'Purchasing','Manager', 'None');

SELECT * FROM ORDER_ITEM WHERE OrderNumber=2000;
SELECT * FROM BUYER WHERE BuyerName LIKE 'Cindy Lo';
SELECT Department, count(*) FROM SKU_DATA group by Department;
/*SELECT * FROM ORDER_ITEM WHERE Department='Yellow' LIMIT 1;*/
SELECT * FROM ORDER_ITEM INNER JOIN SKU_DATA on ORDER_ITEM.SKU=SKU_DATA.SKU;
/*SELECT * FROM ORDER_ITEM HAVING OrderNumber=2000;*/
SELECT * FROM ORDER_ITEM WHERE EXISTS ( SELECT SKU FROM SKU_DATA);
SELECT * FROM RETAIL_ORDER WHERE NOT EXISTS (Select OrderNumber from ORDER_ITEM);