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

void beriNilai(Mahasiswa& m, double nilai, const Dosen& pengajar) 
{
    std::cout << "\nDosen " << pengajar.getNama() << " memberikan nilai " << nilai << " kepada mahasiswa " << m.nama << std::endl;
    m.nilai = nilai;
}

void ubahPangkatDosen(Dosen* dosen, std::string pangkatBaru, const Universitas& universitas) 
{
    universitas.ubahPangkatDosen(dosen, pangkatBaru);
}

void lihatGajiDosen(const Dosen& dosen) 
{
    std::cout << "\nGaji Dosen (diakses melalui getter): Rp " << dosen.getGaji() << std::endl;
}

void lihatGajiStaff(const Staff& staff) 
{
    std::cout << "\nGaji Staff (diakses melalui getter): Rp " << staff.getGaji() << std::endl;
}

int main() 
{
    // Membuat objek-objek menggunakan pointer
    Dosen* dosen1 = new Dosen("12345", "Prof. Dr. Budi Santoso", "Guru Besar", 5000000);
    Mahasiswa* mhs1 = new Mahasiswa("0021", "Siti Aminah", 85.5);
    Staff* staff1 = new Staff("S001", "Andi Wijaya", 3500000);
    Universitas* univ1 = new Universitas();

    // Menampilkan informasi awal
    std::cout << "Informasi Awal:" << std::endl;
    dosen1->tampilkanInfoDosen();
    mhs1->tampilkanInfoMahasiswa();
    staff1->tampilkanInfoStaff();

    // Mahasiswa mengakses informasi dosen melalui friend class
    mhs1->lihatInfoDosen(*dosen1);

    // Dosen memberikan nilai kepada mahasiswa (menggunakan friend function)
    beriNilai(*mhs1, 90.0, *dosen1);
    mhs1->tampilkanInfoMahasiswa();

    // Staff mengubah pangkat dosen melalui friend function dan menggunakan pointer,
    // yang pada akhirnya memanggil method Universitas
    ubahPangkatDosen(dosen1, "Lektor Kepala", *univ1);
    dosen1->tampilkanInfoDosen();

    // Staff melihat gaji dosen melalui friend function
    lihatGajiDosen(*dosen1);

}