-- Keep a log of any SQL queries you execute as you solve the mystery.

-- report about crimes in this street in this date, occur in bakery at 10:15am, interview with three people present in that time, id = 295
SELECT id, street, description FROM crime_scene_reports WHERE day = 28 AND month = 7 AND year = 2023 AND street = 'Humphrey Street';

-- Ruth saw thief leaving bakery parking lot within 10 minutes of theft
-- Eugene saw thief in ATM (withdrawn), Leggett Street, ealier in the monig
-- Raymod ear his call that have a duration less than 1 minute, other person buy a fligth ticket for him in day 29/07/23
SELECT name, transcript FROM interviews WHERE year = 2023 AND month = 7 AND day = 28;

/* license plates:
+---------------+
| license_plate |
+---------------+
| 5P2BI95       |
| 94KL13X       |
| 6P58WS2       |
| 4328GD8       |
| G412CB7       |
| L93JTIZ       |
| 322W7JE       |
| 0NTHK55       |
+---------------+ */
SELECT license_plate FROM bakery_security_logs WHERE year = 2023 AND month = 7
AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25 AND activity = 'exit';

/* plates owner:
+---------+---------------+
|  name   | license_plate |
+---------+---------------+
| Vanessa | 5P2BI95       |
| Barry   | 6P58WS2       |
| Iman    | L93JTIZ       |
| Sofia   | G412CB7       |
| Luca    | 4328GD8       |
| Diana   | 322W7JE       |
| Kelsey  | 0NTHK55       |
| Bruce   | 94KL13X       |
+---------+---------------+ */
SELECT name, license_plate FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2023 AND month = 7
AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25 AND activity = 'exit');

/* atm transactions:
+----------------+
| account_number |
+----------------+
| 28500762       |
| 28296815       |
| 76054385       |
| 49610011       |
| 16153065       |
| 25506511       |
| 81061156       |
| 26013199       |
+----------------+ */
SELECT account_number FROM atm_transactions WHERE year = 2023 AND month = 7
AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

/*
+---------+----------------+
|  name   | account_number |
+---------+----------------+
| Bruce   | 49610011       |
| Diana   | 26013199       |
| Brooke  | 16153065       |
| Kenny   | 28296815       |
| Iman    | 25506511       |
| Luca    | 28500762       |
| Taylor  | 76054385       |
| Benista | 81061156       |
+---------+----------------+ */
SELECT name, account_number FROM people, bank_accounts WHERE people.id = person_id AND account_number IN
(SELECT account_number FROM atm_transactions WHERE year = 2023 AND month = 7 AND day = 28
AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw');


/* possible people:
+-------+
| name  |
+-------+
| Iman  |
| Luca  |
| Diana |
| Bruce |
+-------+ */
SELECT name FROM people WHERE name IN (SELECT name FROM people, bank_accounts WHERE people.id = person_id AND account_number IN
(SELECT account_number FROM atm_transactions WHERE year = 2023 AND month = 7 AND day = 28
AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw')) AND name IN (SELECT name FROM people
WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2023 AND month = 7
AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25 AND activity = 'exit'));


/* flight id and airports id:
+----+-------------------+------------------------+
| id | origin_airport_id | destination_airport_id |
+----+-------------------+------------------------+
| 36 | 8                 | 4                      |
| 43 | 8                 | 1                      |
+----+-------------------+------------------------+ */
SELECT id, origin_airport_id, destination_airport_id FROM flights WHERE year = 2023 AND month = 7
AND day = 29 AND hour < 12;



SELECT name FROM people, passengers WHERE people.passport_number = passengers.passport_number
AND flight_id IN (SELECT id FROM flights WHERE year = 2023 AND month = 7 AND day = 29 AND hour < 12);
