set -euxo pipefail

cd platform/rp2040/make
rm -rf build
mingw32-make XIAO=1
cp build/*.uf2 ../../../
cd ../../..

cd platform/samd21/make
rm -rf build_xiao
mingw32-make -f Makefile_8kbl XIAO=1
cp build_xiao/*.bin ../../../
cd ../../..

cd platform/samd21/make
rm -rf build_qtpy
mingw32-make -f Makefile_8kbl QTPY=1
cp build_qtpy/*.bin ../../../
cd ../../..

uf2conv free_dap_xiao_8kbl.bin --base 0x2000 --family 0x68ed2b88 --output free_dap_xiao_8kbl.uf2
uf2conv free_dap_qtpy_8kbl.bin --base 0x2000 --family 0x68ed2b88 --output free_dap_qtpy_8kbl.uf2
