STM32F4_PenDriveProject_KWPS
============================

#==PL==#

#==:: O Projekcie ::==#

Projekt stworzony przy współpracy Konrad Witkowskiego i Piotra Szczapa.
Projekt ten ma za zadanie obsługę pamięci przenośnych w systemie FAT i FAT32 przy wykorzystaniu złącza użytkowego dostępnego na płytce STM32F407 Discovery.
Program działa poprawnie przy współpracy z pamięciami przenośnymi o pojemności nie większej niż 2GB.
Biblioteka FATFS działa między warstwą aplikacji,którą stworzyliśmy, a warstwą obsługi sprzętu która jest reprezentowana przez bibliotekę ub.

Pamięć przenośna jest podłączana do mikrokontrolera po przez przewód OTG USB z końcówkami Micro-USB [Męskie] i USB A [Żeńskie].

#===::Środowisko programistyczne i konfiguracja kompilatora::===#

Projekt ten został stworzony i zbudowany przy użyciu CooCox IDE- stwrzonym z myślą o procesorach ARM oraz przez kompilator GNU GCC.
Zainstaluj kompilator i środowisko programistyczne, wskaż ścierzkę do kompilatora GCC w programie CooCox IDE i rozpocznij pracę ze swoim mikrokontrolerem.


#===::Sterowniki i  oprogramowanie dla STM32F4xx::===#

Oprogramowanie na płytkę STM32F4xx Discovery  jest przesyłane przy użyciu przewodu USB, aby to zrobić należy w środowisku CoIDE wybrać opcję Program Download. Sterowniki do mikrokontlorera oraz przydatne narzędzia możesz znaleźć na stronie producenta.

#===::Building and Running the Code::===#

Budowanie: W środowisku CoIDE wybierz buduj.
Prześlij program na mikrokonroler: Klinkij na przycisk "Program Download" w środowisku CooCox IDE.
Testowanie: Klinkij na przycisk "Debug" w  CooCox IDE.

#===::Główne założenie::===#
Pierwszym celem jest uruchomienie obsługi PenDrive na płytce STM32F4 Discovery.
Sam program ma za zadanie wykonanie różnych operacji na PenDrive.

#===::Operacje::===#
1. Sprawdzanie zawartości pamięci przenośnej.
2. Wypisywanie statystyk plików zapisanych na pamięci przenośnej.
3. Usuwanie plików.
5. Usuwanie folderów i plików.


#===::Co dalej ?::===#
Nie planujemy dalej rozwijać projektu, jednakże można by dołożyć układ peryferyjny, który pozwolił by stworzyć lepsze menu oraz interfejs użytkownika np. przez dodanie dotykowego wyświetlacza który pozwolił by dodać odpowiednie operacje.



#===::Autorzy::===#

-Konrad Witkowski  
-Piotr Szczap


==========================================
#===::Pomocne materiały::===#
Wszystkie linki znajdują się w pliku: Materiały.txt znajdującym się w głównym folderze projektu.
