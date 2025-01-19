*********************************** README *************************************

Program zawiera implementację dwóch zadań:
1. Wzorzec projektowy "Adapter" - Zadanie 1
2. Wzorzec projektowy "Dekorator" - Zadanie 2

Każde z zadań znajduje się w osobnym bloku w pliku. Aby uruchomić jedno z zadań, należy:
1. Usunąć komentarze oznaczone jako "/* <===+Znacznik do zadania X" (dla odpowiedniego zadania).
2. Pozostawić tylko kod jednego zadania w pliku.
3. W przypadku uruchomienia nowego bloku zadania należy usunąć znacznik z poprzedniego.


***************************** OPIS ZADAŃ ***************************************

Zadanie 1: Wzorzec Adapter
---------------------------
- Implementacja wzorca Adapter, który konwertuje współrzędne prostokątne na biegunowe.
- Kod zawiera klasy:
1. `RobotStary` - korzysta z układu prostokątnego (x, y).
2. `RobotNowy` - korzysta z układu biegunowego (kąt, odległość).
3. `AdapterRobota` - adapter konwertujący współrzędne prostokątne na biegunowe.

WAŻNE:
- Aby uruchomić Zadanie 1:
- Edytuj komentarz "/* <===+Znacznik do zadania 1" na "// <===+Znacznik do zadania 1"
- Upewnij się, że jest dodany komentarz do zadania 2: "/* <===+Znacznik do zadania 2".

Zadanie 2: Wzorzec Dekorator
----------------------------
- Implementacja wzorca Dekorator, który pozwala dodawać nowe funkcje do robota.
- Kod zawiera klasy:
1. `Robot` - podstawowa klasa robota.
2. `RobotPodstawowy` - konkretna implementacja robota, który może się poruszać.
3. `RobotDekorator` - klasa abstrakcyjna rozszerzająca funkcjonalność robota.
4. `RobotZKamera`, `RobotZCzujnikiemTemperatury`, `RobotZDzwiekiem` - dekoratory dodające funkcje.

WAŻNE:
- Aby uruchomić Zadanie 2:
- Edytuj komentarz "/* <===+Znacznik do zadania 2" na "// <===+Znacznik do zadania 2"
- Upewnij się, że jest dodany komentarz do zadania 1: "/* <===+Znacznik do zadania 1".

************************** UWAGI ************************************************
- Użycie inteligentnych wskaźników (`std::shared_ptr`) w zadaniu 2 zapewnia automatyczne zarządzanie pamięcią.
