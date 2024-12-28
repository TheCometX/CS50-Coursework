-- Keep a log of any SQL queries you execute as you solve the mystery.

-- report about crimes in this street in this date, occur in bakery at 10:15am, interview with three people present in that time, id = 295
SELECT id, street, description FROM crime_scene_reports WHERE day = 28 AND month = 7 AND year = 2023 AND street = 'Humphrey Street';

-- Ruth saw thief leaving bakery parking lot within 10 minutes of theft
-- Eugene saw thief in ATM (withdrawn), Leggett Street, ealier in the monig
-- Raymod ear his call that have a duration less than 1 minute, other person buy a fligth ticket for him in day 29/07/23
SELECT name, transcript FROM interviews WHERE year = 2023 AND month = 7 AND day = 28;

