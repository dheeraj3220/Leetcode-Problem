# Write your MySQL query statement below
select c.name AS Customers from Customers AS c
LEFT JOIN Orders AS o 
ON c.id = o.customerid 
where o.customerid IS NULL;