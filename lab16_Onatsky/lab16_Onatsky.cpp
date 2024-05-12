#include <iostream>
#include <string>

class Folder 
{
private:
    std::string name;
    int size;
    std::string creationDate;
    int accessCount;

public:
    Folder(const std::string& n, int s, const std::string& cd, int ac)
        : name(n), size(s), creationDate(cd), accessCount(ac) {}

    std::string getName() const 
    {
        return name;
    }

    int getSize() const 
    {
        return size;
    }

    int getAccessCount() const 
    {
        return accessCount;
    }

    void show() const 
    {
        std::cout << "��'� �����: " << name << std::endl;
        std::cout << "�����: " << size << " ��" << std::endl;
        std::cout << "���� ���������: " << creationDate << std::endl;
        std::cout << "������� ��������: " << accessCount << std::endl;
    }
};

bool compareByName(const Folder& a, const Folder& b) 
{
    return a.getName() < b.getName();
}

bool compareBySize(const Folder& a, int sizeLimit) 
{
    return a.getSize() > sizeLimit;
}

bool compareByAccessCount(const Folder& a, int accessLimit) 
{
    return a.getAccessCount() > accessLimit;
}

int main() 
{
    setlocale(LC_CTYPE, "ukr"); // ��������� ������������ ��������� ����

    Folder folders[] = { Folder("download", 750, "10.03.2024", 130) };

    std::cout << "������ �����, ������������� � ���������� �������:" << std::endl;
    for (const auto& folder : folders) 
    {
        folder.show();
    }
    std::cout << std::endl;

    const int sizeLimit = 500;
    std::cout << "������ �����, ����� ���� �������� " << sizeLimit << " ��:" << std::endl;
    for (const auto& folder : folders) 
    {
        if (compareBySize(folder, sizeLimit)) 
        {
            folder.show();
        }
    }
    std::cout << std::endl;
    
    const int accessLimit = 100;
    std::cout << "������ �����, ����� �������� �� ���� �������� " << accessLimit << ":" << std::endl;
    for (const auto& folder : folders) 
    {
        if (compareByAccessCount(folder, accessLimit)) 
        {
            folder.show();
        }
    }

    return 0;
}
