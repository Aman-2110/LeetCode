Select id, count(id) as num from (SELECT requester_id as id from RequestAccepted
UNION ALL
SELECT accepter_id as id from RequestAccepted
) B
group by id
ORDER BY num DESC
LIMIT 1