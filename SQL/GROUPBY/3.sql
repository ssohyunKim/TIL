SELECT SUBSTRING(DATETIME,11,3) AS HOUR, COUNT(ANIMAL_ID) AS COUNT
FROM ANIMAL_OUTS
WHERE 1=1
GROUP BY HOUR
HAVING HOUR >= 09 AND HOUR <= 19
ORDER BY HOUR
--- SUBSTRING(칼럼명, 시작문자, 갯수) ---