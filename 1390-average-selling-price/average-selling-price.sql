select p.product_id, CASE WHEN (ROUND(SUM(CAST(p.price * u.units as Float))/SUM(u.units), 2)) IS NULL THEN 0 ELSE ROUND(SUM(CAST(p.price * u.units as Float))/SUM(u.units), 2) END as "average_price"
from Prices p left join UnitsSold u
on u.product_id = p.product_id and u.purchase_date >= p.start_date and u.purchase_date <= end_date
group by p.product_id