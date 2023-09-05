# Write your MySQL query statement below
select w2.id
from Weather as w1 
inner join Weather as w2
on (datediff(w2.recordDate , w1.recordDate) = 1 and w2.temperature > w1.temperature)

