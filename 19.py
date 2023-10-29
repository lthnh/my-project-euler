# Monday..Sunday represented as 0..6
# from 1/1/1900 to 1/12/1901 is 365 days. 1900 isn't a leap year.
# > 365%7 = 1 and 1/2/1900 is on Monday so 1/1/1901 is on Tuesday
days_in_months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
start_day = 1
sundays_count = 0
for year in range(1901, 2001):
    if start_day == 6:
        sundays_count += 1
    for month, days in enumerate(days_in_months[:11]):
        if month == 1 and year % 4 == 0:
            days += 1
        start_day = (start_day + days) % 7
        if start_day == 6:
            sundays_count += 1
    start_day = (start_day + days_in_months[11]) % 7
print(sundays_count)