-- Log of SQL queries executed during my investigation


--SUMMARY: 
--         My investigation of the robbery has 8 parts, one for each SQL query made. I begin by looking at the police report.
--         I learn that the thief stole the CS50 Duck from the Humphery Street bakery on July 28th at 10:15am and that three
--         witnesses were interviewed. I continue the investigation by searching for the details of the three interviews.
--         I learn several key pieces of information after reading Ruth, Eugene, and Raymond's statements. This information
--         shaped the rest of my investigation. Ruth's statement leads me to the bakery security logs, where I find license
--         plate numbers of the cars leaving the crime scene within 10 minutes of the robbery. I find the names connected to
--         the plate numbers and find our main suspect, Bruce, along with his phone number and passport number. Next, Eugene's
--         statement leads me to the Leggitt Street ATM, where I search for any transactions made on the day of the crime.
--         I learn that Bruce withdrew money from the ATM. I look at the phone logs next, investigating the information I learned
--         from Raymond's statement. I find that Bruce made a 45s phone call to a person named Robin and suspect Robin is Bruce's
--         accomplice. In the final steps of my investigation, look into flight records and passenger information. I find that
--         Bruce was on the earliest flight leaving Fiftyville, the morning after the crime. He fled to New York City. All of
--         the information I found on Bruce lines up with the statements from the witnesses at this point, so I conclude the
--         investigation and declare Bruce as the thief, who fled to New York City, and Robin as the accomplice, who bought Bruce's
--         plane tickets.


-- QUERY 1: Crime Scene Reports; Humphery Street, 07/28/2021 ----------------------------------------------------------------------------------------

-- Information from the police report.

SELECT *
FROM crime_scene_reports
WHERE year = 2021
AND month = 7
AND day = 28
AND street = 'Humphrey Street';

-- Police Report 295: The thief stole the duck at 10:15am at the Humphery Street bakery.
--                    Three witnesses were interviewed and each witness mentions the bakery.


-- QUERY 2: Interviews; Witness Statements ------------------------------------------------------------------------------------------------------------

-- Statements given by each of the three witnesses.

SELECT *
FROM interviews
WHERE year = 2021
AND month = 7
AND day = 28;

-- RUTH - "Sometime within 10 minutes of the theft, I saw the thief get into a car in the bakery parking lot
--         and drive away. If you have security footage from the bakery parking lot, you might want to look
--         for cars that left the parking lot in that time frame".

-- EUGENE - "I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I
--           arrived at Emma's bakery, I was walking by the ATM on Leggitt Street and saw the thief there
--           pulling out money".

-- RAYMOND - "As the thief was leaving the bakery, they called someone who talked to them for less than a
--            minute. In the call, I heard the thief say that they were planning to take the earliest flight
--            out of Fiftyville tomorrow. The thief the asked the person on the other end of the phone to purchase
--            the flight tickets".


-- QUERY 3 - Bakery Security Logs, License Plate Numbers ---------------------------------------------------------------------------------------------

-- The license plate numbers of the cars exiting the parking lot within 10 minutes of the theft.
-- Additionally, the names, phone numbers, and passport numbers that belong to each of the vehicles'
-- owners.

SELECT *
FROM people AS p
JOIN bakery_security_logs AS bsl
ON bsl.license_plate = p.license_plate
WHERE bsl.year = 2021
AND bsl.month = 7
AND bsl.day = 28
AND bsl.hour = 10
AND bsl.minute BETWEEN 14 AND 26
AND bsl.activity = 'exit';

-- 8 cars left within 10 minutes of the theft, I recorded the first two:

-- CAR 1: Time: 10:16am, Name: Vanessa, Plate Number: 5P2BI95, Phone Number: (725) 555-4692, Passport Number: 2963008352
-- CAR 2: Time: 10:18am, Name: Bruce  , Plate Number: 94KL13X, Phone Numner: (367) 555-5533, Passport Number: 5773159633

-- Query 4: ATM Transactions, Bank Accounts -------------------------------------------------------------------------------------------------------

-- The Leggitt Street ATM-transaction records. A transaction made by Bruce,
-- the same person who left the bakery parking lot at 10:18am. Additionally,
-- Bruce's bank account number, the year Bruce created the account, and how
-- much Bruce withdrew from the ATM.

SELECT *
FROM atm_transactions AS atm
JOIN bank_accounts AS ba
ON ba.account_number = atm.account_number
JOIN people AS p
ON p.id = ba.person_id
WHERE atm.atm_location = 'Leggett Street'
AND atm.transaction_type = 'withdraw'
AND atm.year = 2021
AND atm.month = 7
AND atm.day = 28
ORDER BY atm.id;

-- ATM TRANSACTION 267 - Name: Bruce, Amount: 50, Account Number: 49610011, Creation Year: 2010


-- Query 5: Phone Calls ---------------------------------------------------------------------------------------------------------------------------

-- I search the phone records for any calls on the date of the crime that
-- have a duration of 60 seconds or less. One of the phone calls is made
-- by Bruce. I find the phone number that Bruce called and record it below.

 SELECT *
 FROM phone_calls AS phc
 JOIN people AS p
 ON p.phone_number = phc.caller
 WHERE year = 2021
 AND month = 7
 AND day = 28
 AND duration < 60
 ORDER BY phc.id;

-- PHONE CALL 233 - Receiver: (375) 555-8161, Duration: 45s

-- Query 6: The Accomplice ---------------------------------------------------------------------------------------------------------------------------

-- I search for the name attached to the phone number. I determine that Bruce called someone named Robin.
-- I find Robin's license plate number and non-existant passport number.

SELECT *
FROM people
WHERE phone_number = '(375) 555-8161';

-- PHONE NUMBER (303) 555-8161 - Person ID: 864400, Name: Robin, Passport Number: None, License Plate: 4V16VO0

-- Query 7: Flights & Airports -----------------------------------------------------------------------------------------------------

-- I search for flights that left Fiftyville the day after the crime.
-- I find the eariest flight leaving Fiftyville on 07/29/2021 and record
-- the flight desination and information.

SELECT *
FROM flights
JOIN airports
ON airports.id = flights.destination_airport_id
WHERE year = 2021
AND month = 7
AND day = 29
ORDER BY hour, minute;

-- FLIGHT 36 - Destination (city): New York City, Airport: LaGuardia Airport

-- LAGUARDIA AIRPORT - Airport ID: 4, Abbreviation: LGA


-- Query 8: Passengers -------------------------------------------------------------------------------------------------------------------------------

-- I search the list of passengers on the 8:20am flight to New York City.
-- Bruce's passport number is on the passenger list.

SELECT *
FROM passengers AS p
JOIN flights AS f
ON f.id = p.flight_id
WHERE passport_number = 5773159633;

-- FLIGHT 36, PASSENGERS - Passport Number: 5773159633(Bruce), Seat: 4A

-----------------------------------------------------------------------------------------------------------------------------------------------------
