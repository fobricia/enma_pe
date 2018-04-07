<h1 align="center">ENMA PE</h1>
---

| License | Windows x32 | Windows x64 | Linux |
| ------- | ----------- | ----------- | ----- |
| [![License](https://img.shields.io/badge/license-LGPLv3%2B-blue.svg)](https://github.com/jnastarot/enma_pe/blob/master/LICENSE) | [![Build status](https://ci.appveyor.com/api/projects/status/ogdbdwhomqi1yoh1?svg=true)](https://ci.appveyor.com/project/jnastarot/enma-pe) | [![Build status](https://ci.appveyor.com/api/projects/status/b6bq9w9b1b7rjaoy?svg=true)](https://ci.appveyor.com/project/jnastarot/enma-pe-u6wir) | [![Build Status](https://api.travis-ci.org/jnastarot/enma_pe.svg?branch=master)](https://api.travis-ci.org/jnastarot/enma_pe) |




```
--------------------------------------------------------------------------------
Name....: enma pe
Author..: JNA
Date....: 2018
e.mail..: jnastarot@yandex.ru
--------------------------------------------------------------------------------
```
---
<h2 align="center">Supported PE\PE+ formats</h1>

| directory name | reading | building | getting placement |
| :-------------- | :-------: | :-------: | :-------: |
| `export` | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |
| `import default ` | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |
| `import bound ` | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |
| `import delay` | :heavy_check_mark: | :heavy_multiplication_x: | :heavy_check_mark: |
| `resources` | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |
| `exceptions` | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |
| `security` | :heavy_multiplication_x: | :heavy_multiplication_x: | :heavy_check_mark: |
| `relocations` | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |
| `debug` | :heavy_check_mark: | :heavy_multiplication_x: | :heavy_check_mark: |
| `tls` | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |
| `load config` | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |
| `.NET meta data` | :heavy_check_mark: | :heavy_multiplication_x: | :heavy_multiplication_x: |

---

<h3 align="center">additional functionality</h1>

|  | description |
| :------: | :-----------: |
| `map parser` | parsing .map file generated by delphi XE and Visual Studio |
| `tds parser` | parsing tds-styled debug info |
| `string finder` | finding ansi and unicode strings |
---

| credits |
| ---------- |
| pe rich comp id [richprint](https://github.com/dishather/richprint/) |
| reading\building of export and resources [pe bliss kaimi](http://kaimi.io/) |
| tds parser [denisenkomik.narod.ru/main.cpp](http://denisenkomik.narod.ru/main.cpp) |

<p align="center">
<iframe frameborder="0" allowtransparency="true" scrolling="no" src="https://money.yandex.ru/embed/donate.xml?account=410011886390588&quickpay=donate&payment-type-choice=off&default-sum=100&targets=for+a+good+cause&project-name=&project-site=&button-text=05&successURL=" width="423" height="64"></iframe>
</p>


