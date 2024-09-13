# 67602_locale

## Build and install

```console
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```

## Run

```console
$ ./dist/bin/localeinfo --help
Usage: localeinfo ABBR
    Print properties of the locale whose abbreviation is ABBR.

$ ./dist/bin/localeinfo en_ZM.utf8
 -- Properties
 --     en_ZM.utf8
 -- Non-monetary
 --     decimal_point      = .
 --     thousands_sep      = ,
 --     grouping           = 3
 -- Monetary
 --     mon_decimal_point  = .
 --     mon_thousands_sep  = ,
 --     mon_grouping       = 3
 --     positive_sign      = 
 --     negative_sign      = -
 --     currency_symbol    = K
 --     int_curr_symbol    = ZMW 
 -- Local formatting
 --     frac_digits        = 2
 --     p_cs_precedes      = 1
 --     n_cs_precedes      = 1
 --     p_sep_by_space     = 0
 --     n_sep_by_space     = 0
 --     p_sign_posn        = 1
 --     n_sign_posn        = 1
 -- International formatting
 --     int_frac_digits    = 2
 --     int_p_cs_precedes  = 1
 --     int_n_cs_precedes  = 1
 --     int_p_sep_by_space = 0
 --     int_n_sep_by_space = 0
 --     int_p_sign_posn    = 1
 --     int_n_sign_posn    = 1
```

