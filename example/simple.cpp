
#include <iostream>

#include "../src/TarFile.h"

int main(int ac, char *av[]) {
    auto tf = tarfile::TarFile::constructFromFile("test");

    return 0;
}
