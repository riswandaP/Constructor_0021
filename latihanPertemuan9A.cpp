#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Mahasiswa;
class Dosen;
class Staff;
class Universitas;

void lihatGajiDosen(const Dosen& dosen);
void lihatGajiStaff(const Staff& staff);
void beriNilai(Mahasiswa& m, double nilai, const Dosen& pengajar);
void ubahPangkatDosen(Dosen* dosen, std::string pangkatBaru, const Universitas& universitas);

