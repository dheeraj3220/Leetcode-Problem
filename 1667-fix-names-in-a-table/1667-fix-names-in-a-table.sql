# Write your MySQL query statement below
select user_id, 
CONCAT(UPPER(SUBStr(name,1,1)),LOWER(SUBSTR(name,2,length(name)-1))) 
AS name 
from Users 
order by user_id;
