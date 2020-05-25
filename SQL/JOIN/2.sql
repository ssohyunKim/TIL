-- 보호 시작일보다 입양일이 더 빠른 : ANIMAL_OUTS.DATETIME < ANIMAL_INS.DATETIME

SELECT A.ANIMAL_ID, A.NAME
FROM ANIMAL_OUTS AS A
INNER JOIN ANIMAL_INS AS B
ON A.ANIMAL_ID = B.ANIMAL_ID
WHERE A.DATETIME < B.DATETIME
ORDER BY B.DATETIME

-- ORACLE
-- 오라클은 테이블 명 AS 못쓴다.
SELECT A.ANIMAL_ID, A.NAME
FROM ANIMAL_INS A, ANIMAL_OUTS B
WHERE A.ANIMAL_ID = B.ANIMAL_ID
AND A.DATETIME > B.DATETIME
ORDER BY A.DATETIME;