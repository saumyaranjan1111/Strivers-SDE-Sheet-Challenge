# Write your MySQL query statement below
select a.machine_id, round(sum(b.timestamp - a.timestamp)/count(*), 3) as processing_time
from Activity as a, Activity as b
where (a.machine_id = b.machine_id and a.process_id = b.process_id) and (a.activity_type = 'start' and b.activity_type = 'end')
group by a.machine_id;
