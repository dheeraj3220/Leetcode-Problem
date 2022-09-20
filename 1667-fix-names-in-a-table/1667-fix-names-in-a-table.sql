# Write your MySQL query statement below
select user_id, CONCAT(UPPER(SUBSTRING(name,1,1)),LOWER(SUBSTRING(name,2,length(name)-1))) AS name from Users order by user_id

                       
                       
#                        SELECT user_id, concat(upper(substring(name,1,1)),lower(substring(name,2,length(name)-1))) as name FROM Users
# order by user_id