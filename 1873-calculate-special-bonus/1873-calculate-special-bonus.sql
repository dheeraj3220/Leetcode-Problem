# Write your MySQL query statement below
select employee_id,if(employee_id%2 AND name NOT LIKE "M%",salary,0) AS bonus from employees order by employee_id; 