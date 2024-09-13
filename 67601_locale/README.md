# 67601_locale

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
Usage: localeinfo
    Print properties of the C locale and the native locale.

$ ./dist/bin/localeinfo
 -- Properties of C locale:
 -- C
 --     Non-monetary
 --         decimal_point      = .
 --         thousands_sep      = 
 --         grouping           = 0
 --     Monetary
 --         mon_decimal_point  = 
 --         mon_thousands_sep  = 
 --         mon_grouping       = 0
 --         positive_sign      = 
 --         negative_sign      = 
 --         currency_symbol    = 
 --         int_curr_symbol    = 
 --     Local formatting
 --         frac_digits        = 127
 --         p_cs_precedes      = 127
 --         n_cs_precedes      = 127
 --         p_sep_by_space     = 127
 --         n_sep_by_space     = 127
 --         p_sign_posn        = 127
 --         n_sign_posn        = 127
 --     International formatting
 --         int_frac_digits    = 127
 --         int_p_cs_precedes  = 127
 --         int_n_cs_precedes  = 127
 --         int_p_sep_by_space = 127
 --         int_n_sep_by_space = 127
 --         int_p_sign_posn    = 127
 --         int_n_sign_posn    = 127
 -- 
 -- Properties of native locale:
 -- en_US.UTF-8
 --     Non-monetary
 --         decimal_point      = .
 --         thousands_sep      = ,
 --         grouping           = 3
 --     Monetary
 --         mon_decimal_point  = .
 --         mon_thousands_sep  = ,
 --         mon_grouping       = 3
 --         positive_sign      = 
 --         negative_sign      = -
 --         currency_symbol    = $
 --         int_curr_symbol    = USD 
 --     Local formatting
 --         frac_digits        = 2
 --         p_cs_precedes      = 1
 --         n_cs_precedes      = 1
 --         p_sep_by_space     = 0
 --         n_sep_by_space     = 0
 --         p_sign_posn        = 1
 --         n_sign_posn        = 1
 --     International formatting
 --         int_frac_digits    = 2
 --         int_p_cs_precedes  = 1
 --         int_n_cs_precedes  = 1
 --         int_p_sep_by_space = 1
 --         int_n_sep_by_space = 1
 --         int_p_sign_posn    = 1
 --         int_n_sign_posn    = 1
```

