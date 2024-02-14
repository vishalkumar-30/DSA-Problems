# Write your MySQL query statement below
SELECT Sales.year, Sales.price, Product.product_name
From Sales 
LEFT JOIN Product
ON Sales.product_id = Product.product_id;
