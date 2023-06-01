# LEMLAT 3.0

## About

Contribution of the [CIRCSE Research Centre](https://centridiricerca.unicatt.it/circse_index.html) to the Latin morphological analyzer and lemmatizer **LEMLAT 3.0**.

**NB: LEMLAT analyzes *types*, not *tokens*; it doesn't therefore disambiguate words in context.**


LEMLAT 3.0 website: http://www.lemlat3.eu/<br />
LEMLAT 3.0 credits: http://www.lemlat3.eu/about/credits/

To cite LEMLAT 3.0 (first release), you can adapt the following:

>Marco Passarotti, Paolo Ruffolo, Flavio M. Cecchini, Eleonora Litta, Marco Budassi (2018) *LEMLAT 3.0*. [![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.1492134.svg)](https://doi.org/10.5281/zenodo.1492134)

To cite **all versions/releases** of LEMLAT 3.0 use DOI: https://doi.org/10.5281/zenodo.1492133

## Documentation and use

See the [Wiki of this repository](https://github.com/CIRCSE/LEMLAT3/wiki) for the full documentation and instructions on how to run LEMLAT 3.0.

## Building the client library for python

In ubuntu 20.04:
```bash
apt-get install libmariadbclient-dev libmariadb-dev libmariadbd-dev gnutls-dev libssl-dev libcrypto++-dev libaio-dev liblz4-dev libnuma-dev
cd LEMLAT3/lemlat_workspace/LemLat_client
bash build_all.linux.64.sh
make -f Makefile.linux sOut.o
make -f Makefile.linux lib
```

## Updating the embedded database
```bash
apt-get install mariadb-server
cd LEMLAT3/lemlat_workspace/LemLat_client
# edit bin.linux/embeddedD/my_gen.cnf first, symlink /usr/bin, /usr/sbin/, /usr/share to bin.linux/embdeddedD
mysql_install_db --defaults-file=my_gen.cnf
bash update_embedded_db.linux.sh
```


## Copyright

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="Creative Commons Licence" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a><br />LEMLAT 3.0 is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.
