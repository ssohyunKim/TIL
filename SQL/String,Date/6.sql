-- 각 동물의 아이디와 이름, 들어온 날짜를 조회
-- 결과는 아이디 순으로 조회해야 합니다.

SELECT ANIMAL_ID, NAME, DATE_FORMAT(DATETIME, '%Y-%m-%d') AS 날짜
FROM ANIMAL_INS
WHERE 1=1
ORDER BY ANIMAL_ID
