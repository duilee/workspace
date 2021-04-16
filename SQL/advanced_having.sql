/* Get hacker_id, name, count of challenges created */
SELECT c.hacker_id, h.name, COUNT(c.hacker_id)
/* from Challenges table inner joined with hackers table. */
FROM Challenges AS c INNER JOIN Hackers AS h
ON c.hacker_id = h.hacker_id
/* Group results by hacker_id */
GROUP BY c.hacker_id, h.name
/* and use HAVING (which is like a WHERE for a GROUP BY) to select
   hacker_ids that produced the max number of challenges */
/* Note: The statement on the right of the equals sign selects max number of challenges created*/
    HAVING COUNT(c.challenge_id) = (SELECT MAX(cnts.cnt) 
                                 FROM (SELECT COUNT(hacker_id) AS cnt 
                                       FROM Challenges 
                                       GROUP BY hacker_id) AS cnts)
/* or where only one hacker created that number of challenges. */
/* Note: The statement on the right of the IN clause selects the numbers of challenges created that were only achieved by one hacker (e.g. only one hacker made exactly 42 challenges). */
    OR COUNT(c.challenge_id) IN (SELECT cnts.cnt 
                              FROM (SELECT COUNT(hacker_id) AS cnt
                                    FROM Challenges
                                    GROUP BY hacker_id) AS cnts
                              GROUP BY cnts.cnt
                                HAVING COUNT(cnts.cnt) = 1)
/* Sort results by number of challenges made, then by hacker_id. */
ORDER BY COUNT(c.hacker_id) DESC, hacker_id
