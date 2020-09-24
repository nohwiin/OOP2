Design a movie booking system
===
Movie booking system
---
Create a program can book movie tickets and manage it.</br>
User can access this program with their own account'

User
---
There are two types users. Administrator & customer.</br>
If user access to the program with their Account, Program find their type and show different menu</br>
1. User Data
>Program has two types data file.</br>
>pass.dat : It has ID and encrpted password.</br>
>"ID".dat : personal data for each user. File name is user's ID(abc.dat, cdf.dat, etc.). It has ID, e-mail, authority(administrator or customer) and booking history(no password in this file)</br>

Login process
---
first, let user to select menu between "login", "new account", "find password", "Quit"
1. Login : user enter ID and password.</br>
>Judge by comparision with pass.dat and find authority in personal data file and show menu according to the authority
2. New Account
>User enter ID, password, password once more, and email.</br>
>Program save the data in files.(password must be encrypted before saving)
3. Find password : Uswer enter ID and email.
>Program compare it to personal data. If it's equal show decrypted password.
4. Quit : Exit program

Movie schedule
---
Assume there are several Auditorium(at least 3) and has different schedule.</br>
Program has schedule files(Aud1.dat, Aud2.dat, etc.) and administrator can manage it.
1. schedule has componenet(type) below
>MovieNumber(int) : specify schedule</br>
>Starting time(int or else) : movie starting time.</br>
>End time(int or else) : time movie finished.</br>
>Moviename(string or char*) : name of movie</br>
>Leftseat(int) : number of seats left</br>
>Price(double) : price of movie</br>
>Seats(bool* or else*) : array of seat. Represent the seats are occupied or not

Method for administrator
---
Administrator can manage user & schedule
1.Schedule management
>Show schedule : program show the schedule exists.</br>
>Add schedule : add schedule to the file. Schedule must not be overlapped.</br>
>Update schedule : Update schedule in the file. Change time, movie name, etc.</br>
>Delete schedule : delete schedule from file. You must delete all the history in user personal data.
2. User management
>Set authority : change user authority</br>
>Show user list : show all user's ID and e-mail</br>
>Delete uswer : delete user data.</br>
