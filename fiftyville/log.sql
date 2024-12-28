-- Keep a log of any SQL queries you execute as you solve the mystery.

-- report about crimes in this street in this date, occur in bakery at 10:15am, interview with three people present in that time, id = 295
SELECT id, street, description FROM crime_scene_reports WHERE day = 28 AND month = 7 AND year = 2023 AND street = 'Humphrey Street';

-- Ruth saw thief leaving bakery parking lot within 10 minutes of theft
-- Eugene saw thief in ATM (withdrawn), Leggett Street, ealier in the monig
-- Raymod ear his call that have a duration less than 1 minute, other person buy a fligth ticket for him in day 29/07/23
SELECT name, transcript FROM interviews WHERE year = 2023 AND month = 7 AND day = 28;

/* possible plate:
5P2BI95
94KL13X
6P58WS2
4328GD8
G412CB7
L93JTIZ
322W7JE
0NTHK55 */
SELECT activity, license_plate FROM bakery_security_logs WHERE year = 2023
AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND minute > 05;


/* possible bank accounts:
28500762
28296815
76054385
49610011
16153065
25506511
81061156
26013199 */
SELECT account_number, amount FROM atm_transactions WHERE year = 2023 AND month = 7
AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

/* Owners of plates (suspects):
+---------+----------------+-----------------+
|  name   |  phone_number  | passport_number |
+---------+----------------+-----------------+
| Vanessa | (725) 555-4692 | 2963008352      |
| Barry   | (301) 555-4174 | 7526138472      |
| Brandon | (771) 555-6667 | 7874488539      |
| Iman    | (829) 555-5269 | 7049073643      |
| Sofia   | (130) 555-0289 | 1695452385      |
| Luca    | (389) 555-5198 | 8496433585      |
| Diana   | (770) 555-1861 | 3592750733      |
| Kelsey  | (499) 555-9472 | 8294398571      |
| Bruce   | (367) 555-5533 | 5773159633      |
| Sophia  | (027) 555-1068 | 3642612721      |
+---------+----------------+-----------------+ */
SELECT name, phone_number, passport_number FROM people WHERE license_plate IN (SELECT license_plate
FROM bakery_security_logs WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND minute > 05);

/* Owners of bank accounts:
+---------+----------------+-----------------+
|  name   |  phone_number  | passport_number |
+---------+----------------+-----------------+
| Bruce   | (367) 555-5533 | 5773159633      |
| Diana   | (770) 555-1861 | 3592750733      |
| Brooke  | (122) 555-4581 | 4408372428      |
| Kenny   | (826) 555-1652 | 9878712108      |
| Iman    | (829) 555-5269 | 7049073643      |
| Luca    | (389) 555-5198 | 8496433585      |
| Taylor  | (286) 555-6063 | 1988161715      |
| Benista | (338) 555-6650 | 9586786673      |
+---------+----------------+-----------------+ */
SELECT name, phone_number, passport_number FROM people, bank_accounts, atm_transactions
WHERE atm_transactions.account_number = bank_accounts.account_number AND person_id = people.id
AND year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';
