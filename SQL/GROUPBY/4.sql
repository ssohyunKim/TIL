-- SET을 이용해서 변수 hour변수 설정. @를 붙인다 --- 
SET @hour = -1;
SELECT
    (@hour := @hour +1) as HOUR,
    (SELECT COUNT(*) FROM ANIMAL_OUTS WHERE HOUR(DATETIME) = @hour) AS COUNT
FROM ANIMAL_OUTS 
WHERE @hour < 23