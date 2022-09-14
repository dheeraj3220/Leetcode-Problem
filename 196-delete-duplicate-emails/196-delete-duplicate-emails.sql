# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
DELETE FROM Person
WHERE Id NOT IN (
  SELECT * FROM (
    SELECT Min(Id)
    FROM Person
    GROUP BY Email
  ) Tmp
)
