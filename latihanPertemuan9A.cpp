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

class Mahasiswa 
{
private:
    std::string NIM;
    std::string nama;
    double nilai;
    friend class Dosen;
    friend class Universitas;
    friend void lihatGajiDosen(const Dosen& dosen);
    friend void beriNilai(Mahasiswa& m, double nilai, const Dosen& pengajar);
    friend void ubahPangkatDosen(Dosen* dosen, std::string pangkatBaru, const Universitas& universitas);

public:
    Mahasiswa(std::string nim, std::string nm, double nil) : NIM(nim), nama(nm), nilai(nil) {}

    void tampilkanInfoMahasiswa() const 
    {
        std::cout << "NIM: " << NIM << std::endl;
        std::cout << "Nama Mahasiswa: " << nama << std::endl;
        std::cout << "Nilai: " << nilai << std::endl;
    }

    void lihatInfoDosen(const Dosen& dosen) const;

    // Getter untuk nama
    std::string getNama() const
    {
        return nama;
    }

    // Getter untuk nilai
    double getNilai() const 
    {
        return nilai;
    }

};
