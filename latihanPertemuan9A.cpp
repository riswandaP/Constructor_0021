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

class Dosen 
{
private:
    std::string NIDN;
    std::string nama;
    std::string pangkat;
    double gaji;
    friend class Mahasiswa; // Mahasiswa bisa melihat info dosen
    friend class Universitas; // Universitas bisa mengakses gaji untuk keperluan administrasi (misalnya)
    friend void lihatGajiDosen(const Dosen& dosen);
    friend void beriNilai(Mahasiswa& m, double nilai, const Dosen& pengajar);
    friend void ubahPangkatDosen(Dosen* dosen, std::string pangkatBaru, const Universitas& universitas);

public:
    Dosen(std::string nidn, std::string nm, std::string pkt, double gj) : NIDN(nidn), nama(nm), pangkat(pkt), gaji(gj) {}

    double getGaji() const 
    {
        return gaji;
    }

    std::string getNama() const 
    {
        return nama;
    }

    void tampilkanInfoDosen() const 
    {
        std::cout << "NIDN: " << NIDN << std::endl;
        std::cout << "Nama Dosen: " << nama << std::endl;
        std::cout << "Pangkat: " << pangkat << std::endl;
        std::cout << "Gaji: Rp " << gaji << std::endl;
    }
};

void Mahasiswa::lihatInfoDosen(const Dosen& dosen) const {
    std::cout << "\nInformasi Dosen Pembimbing:" << std::endl;
    std::cout << "  NIDN: " << dosen.NIDN << std::endl;
    std::cout << "  Nama: " << dosen.nama << std::endl;
    std::cout << "  Pangkat: " << dosen.pangkat << std::endl;
    std::cout << "  Gaji: Rp " << dosen.gaji << std::endl;
}

class Staff 
{
private:
    std::string IDStaff;
    std::string nama;
    double gaji;
    friend class Universitas; // Universitas bisa mengakses gaji staff
    friend void lihatGajiStaff(const Staff& staff);

public:
    Staff(std::string id, std::string nm, double gj) : IDStaff(id), nama(nm), gaji(gj) {}

    double getGaji() const 
    {
        return gaji;
    }

    std::string getNama() const 
    {
        return nama;
    }

    void tampilkanInfoStaff() const 
    {
        std::cout << "ID Staff: " << IDStaff << std::endl;
        std::cout << "Nama Staff: " << nama << std::endl;
        std::cout << "Gaji: Rp " << gaji << std::endl;
    }
};

class Universitas 
{
public:
    void ubahPangkatDosen(Dosen* dosen, std::string pangkatBaru) const 
    {
        if (dosen != nullptr) 
        {
            dosen->pangkat = pangkatBaru;
            std::cout << "\nUniversitas: Pangkat dosen " << dosen->getNama() << " berhasil diubah menjadi: " << pangkatBaru << std::endl;
        } 
        else 
        {
            std::cout << "\nUniversitas: Error - Pointer dosen tidak valid." << std::endl;
        }
    }

    void lihatGajiStaff(const Staff& staff) const 
    {
        std::cout << "\nUniversitas: Gaji Staff " << staff.getNama() << " adalah: Rp " << staff.getGaji() << std::endl;
    }
};
