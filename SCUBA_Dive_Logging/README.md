## SCUBA_Dive_Logging fuzzer
https://github.com/trailofbits/cb-multios/tree/master/challenges/SCUBA_Dive_Logging

## Application information
SCUBA_Dive_Logging provides an interface for a single diver to record both information about themself and information on the various dives that they have performed. SCUBA_Dive_Logging also allows the user to download, edit, print, and remove dive logs.

The application stores the divers full name, address (street, city, state, and ZIP code), phone number, PADI diver number, and PADI certification date. The information that the application stores on the dives that the diver has performed includes the site, date, time, location, max and average depth, duration, O2 percentage, pressure in, and pressure out.

The application presents a menu with eight options: Change diver info, Log a new dive, Download dive data, Edit dives, Print dive logs, Remove dives, Diver statistics, and Exit application. Change diver info and log new dive simply request the user for the information that the application normally stores on the diver and the dives, respectively. Download dive data requires at least 32 hex values (received four at a time) before being terminated by the hex string "\x00\x00\x00\x00", at which point the application proceeds as though log new dive had been selected. Print and Remove dives both present an indexed list of logged dives (starting at 1). If the user chooses a valid index, the application prints or removes that dive, respectively. Edit dives also requires an index, and if valid, acts as though log new dive had been chosen. Diver statistics simply presents various statistics on the diver and requires no further user input. Exit application exits the application.

## Vulnerabilities
SCUBA_Dive_Logging has two vulnerabilities:
1. The size of input strings when editing and logging dives are usually limited in order to fit into a string buffer. However, the string size for dive site in the edit dives function is not limited in such a way. This allows an overly large string to be written to the buffer, which overwrites several other members of the data structure, including the pointer to the next dive in the linked list. When the dive list is next accessed (via log new dive, edit dives, print dive logs, or remove dives) the application will crash.
2. When dive data is downloaded, samples (consisting of a timestamp and depth) are collected into a linked list. The timestamp values are used to allocate an array. The linked list is then passed through again and the values of the sample are used to calculate where in the array they should be placed. However, these values are not sanitized, which means that a corrupted value may be allocated outside of the array, which will crash the application.

## Fuzzer information
The fuzzer sends 66 ints, which the relay then converts into an expression suitable for the application. The usage and expected ranges for the generated integers are as follows:

    Variable Name       Usage                                       Expected Range      Instances
    main                Represents the main command                 [0,7]               1
    cha                 Represents chars based on ASCII conversion  [32, 126]           25
    month               Represents the month                        [1, 12]             1
    day                 Represents the day                          [1, 31]             1
    year                Represents the year                         [1950, 2050]        1
    genericIn           Represents various input values             unconstrained       1 (ZIP, phone, PADINum, maxDep, avgDep, durat, O2, PSIIn, PSIOut)
    time                Represents a time value                     unconstrained       3
    hexVal              Represents a hex value                      [0, 255]            32
    index               Represents the dive index                   [1, 20]             1

Due to the large amount of varying input the application requires for each different command, fuzzed values are reused where possible. Specifically, two strings and the date value are shared between the change diver info and log new dive, and the index value of edit, print, and remove dives are shared. Log new dive, Edit dives, and Download dives also share the same fuzzer input. Due to the fact that only one command is called at a time, this does not present a problem in exploring possible execution states.

    The relay always sends the main menu command and then determines what to send based on that value.
    If main is 0 (change diver info) or 1 (log new dive), the relay will send the information that the application requests for the specific command.
    If main is 2 (download dive), the relay splits the fuzzed hex values into eight sets of four consecutive values, sends the eight sets consecutively one at a time, then sends "\x00\x00\x00\x00" at which point the relay acts as though log new dive had been selected.
    If main is 3 (edit dives), 4 (print dive), or 5 (remove dive), the relay sends the index value. If edit dives was selected, the relay then acts as though log new dive had been selected.

## Running the fuzzer
The fuzzer files must be named SCUBA_Dive_Logging.c in order to build properly.
Run the make file found in the build folder.
Once the build process is complete, run fuzz.sh in the bin folder.
