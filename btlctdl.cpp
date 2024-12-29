#include<bits/stdc++.h>
using namespace std;

// Structs
struct Reader {
    string name_reader;
    int mssv;
    Reader* Next;
};

struct Book {
    string tensach;
    string tacgia;
    string nhaxuatban;
    string theloai;
    string masosach;
    int soluong;
    bool tinhtrang;
    Book* next;
    Reader* nguoidoc;
};

typedef Book  *book;
typedef Reader *reader;

// Hàm tạo và xử lý sách
book makeBook(string tensach, string tacgia, string nxb, string theloai, string masosach, int soluong) {
    book tmp = new Book();
    tmp->tensach = tensach;
    tmp->tacgia = tacgia;
    tmp->nhaxuatban = nxb;
    tmp->theloai = theloai;
    tmp->masosach = masosach;
    tmp->soluong = soluong;
    tmp->tinhtrang = false;
    tmp->next = nullptr;
    tmp->nguoidoc = nullptr;
    return tmp;
}
bool bookisempty(book A) {
    return A == NULL;
}

void initbook(book &A) {
    A = NULL;
}
int countBooks(book head){
    int count =0;
    while(head){
        count++;
        head=head->next;
    }
    return count;
}

//them sach
void insertBook(book &BOOK, string tensach, string tacgia, string nxb, string theloai, string masosach, int soluong) {
    book newBook = makeBook(tensach, tacgia, nxb, theloai, masosach, soluong);
    while(1){
        if(newBook==BOOK){
            BOOK->soluong +=soluong;
            break;
        }
        BOOK->next;
        if(BOOK==NULL){
            BOOK = newBook;
            break;
        }
    }
    cout << "thêm sách thành công\n";
}

//sửa thông tin sách
void updateBook(book BOOK) {
    string id;
    cout << "Nhập mã số sách cần cập nhật: ";
    cin >> id;

    while(!BOOK){
        if(id==BOOK->masosach){
            int choice;
            do{
                cout << "\n----- Cập nhật thông tin sách -----\n";
                cout << "1. Sửa thông tin sách\n";
                cout << "2. Sửa tên tác giả\n";
                cout << "3. Sửa nhà xuất bản\n";
                cout << "4. Sửa thể loại\n";
                cout << "5. Sửa số lượng sách\n";
                cout << "6. Thoát cập nhật\n";
                cout << "Lựa chọn của bạn: ";
                cin >> choice;

                cin.ignore(); // Xử lý buffer trước khi dùng getline
                switch (choice) 
                {
                    case 1:
                    {
                        cout << "Nhập tên sách mới: ";
                        getline(cin, BOOK->tensach);
                        cout << "Tên sách đã được cập nhật.\n";
                        break;                    
                    }
                    case 2:
                    {
                        cout << "Nhập tên tác giả mới: ";
                        getline(cin, BOOK->tacgia);
                        cout << "Tên tác giả đã được cập nhật.\n";
                        break;
                    }
                    case 3:{
                        cout << "Nhập tên nhà xuất bản mới: ";
                        getline(cin, BOOK->nhaxuatban);
                        cout << "Tên nhà xuất bản đã được cập nhật.\n";
                        break;}
                    case 4:{
                        cout << "Nhập thể loại mới: ";
                        getline(cin, BOOK->theloai);
                        cout << "Thể loại đã được cập nhật.\n";
                        break;}
                    case 5:{
                        cout << "Nhập số lượng sách mới: ";
                        cin >> BOOK->soluong;
                        cout << "Số lượng sách đã được cập nhật.\n";
                        break;}
                    case 6:{
                        cout << "Thoát cập nhật thông tin sách.\n";
                        break;}
                    default:{
                        cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại.\n";
                        break;}
                }
            } while (choice != 6);
            break;
        }
        BOOK->next;
        if(BOOK==NULL){
            cout << "Không tìm thấy sách có mã số: " << id << endl;
        }
    }
}

// Hien thi thong tin day du cua sach
void displayBookInfo(book b) {
    if (b != NULL) {
        cout << "Mã số sách: " << b->masosach << endl;
        cout << "Tên sách: " << b->tensach << endl;
        cout << "Tác giả: " << b->tacgia << endl;
        cout << "Nhà xuất bản: " << b->nhaxuatban << endl;
        cout << "Thể loại: " << b->theloai << endl;
        cout << "Số lượng: " << b->soluong << endl;
    } else {
        cout << "Không có thông tin để hiển thị." << endl;
    }
}

//tìm kiếm sách theo mã số sách
   book searchBook(book &BOOK, const string &masosach) {
    book Books = BOOK; // Books = Library
    int i=0;
    while (Books != NULL) {
        if (Books->masosach != masosach) {
            deleteBooks(Books,Books->masosach);
        }
        else{
            i++;
        }
        Books = Books->next;
    }
    if(i!=0) {
        cout << "Tim thay i ket qua tuong ung voi masosach:" << endl;
        // hien thi Books
        return Books;
    }
    else{
        cout << "Không tìm thấy sách với mã số: " << masosach << endl;
        return NULL;
    }
    
}

//tìm kiếm sách theo tên sách
book searchBookbytitle(book &BOOK, string tensach) {
    book Books = BOOK; // Books = Library
    int i=0;
    while (Books != NULL) {
        if (Books->tensach != tensach) {
           deleteBooks(Books,Books->tensach);
        }
        else{
            i++;
        }
        Books = Books->next;
    }
    if(i!=0) {
        cout << "Tim thay i ket qua tuong ung voi tensach:" << endl;
        // hien thi Books
        return Books;
    }
    else{
        cout << "Không tìm thấy sách với ten sach: " << tensach << endl;
    }
}

//tìm kiêm theo thể loại
book searchBookbycategory(book &BOOK, string theloai) {
    book *Books = BOOK; // Books = Library
    int i=0;
    while (Books != NULL) {
        if (Books->theloai != theloai) {
          deleteBooks(Books,Books->theloai);
        }
        else{
            i++;
        }
        Books = Books->next;
    }
    if(i!=0) {
        cout << "Tim thay i ket qua tuong ung voi the loai:" << endl;
        // hien thi Books
        return Books;
    }
    else{
        cout << "Không tìm thấy sách với the loai: " << theloai << endl;
    }
    
}

//tìm kiêm theo tác giả
book searchBookbyAuthor(book &BOOK, string tacgia) {
   book *Books = BOOK; // Books = Library
    int i=0;
    while (Books != NULL) {
        if (Books->tacgia != tacgia) {
          deleteBooks(Books,Books->tacgia);// xoa di nhung node khong giong
        }
        else{
            i++;
        }
        Books = Books->next;
    }
    if(i!=0) {
        cout << "Tim thay i ket qua tuong ung voi tac gia:" << endl;
        // hien thi Books
        return Books;
    }
    else{
        cout << "Không tìm thấy sách với tac gia: " << tacgia << endl;
    }
    
}
void deleteNode(book &A, book P) {
    if (A == NULL || P == NULL) {
        cout << "sách trống hoặc không tìm thấy sách\n";
        return;
    }
    if (A == P) {
        A = P->next;
        delete P;
        return;
    }
    book R = A;
    while (R->next != P && R->next != NULL) {
        R = R->next;
    }
    if (R->next == P) {
        R->next = P->next;
        delete P;
    }
}

//xóa sách
void deleteBooks(book &A, string id) {
    book P = searchBook(A, id);
    //đảo từ id -> -> ra cuối
    // Xóa node cuốicuối
    deleteNode(A, P);
    
}

//sxep sach theo thu tu ma so tang dan
void swapinfoBook(book book1,book book2){
    string tmp1;
    int tmp2;
    tmp1=book1->tensach;
    book1->tensach=book2->tensach;
    book2->tensach=tmp1;

    tmp1=book1->tacgia;
    book1->tacgia=book2->tacgia;
    book2->tacgia=tmp1;

    tmp1=book1->nhaxuatban;
    book1->nhaxuatban=book2->nhaxuatban;
    book2->nhaxuatban=tmp1;

    tmp1=book1->theloai;
    book1->theloai=book2->theloai;
    book2->theloai=tmp1;

    tmp1=book1->masosach;
    book1->masosach=book2->masosach;
    book2->masosach=tmp1;

    tmp2=book1->soluong;
    book1->soluong=book2->soluong;
    book2->soluong=tmp2;

    bool tmp3 = book1->tinhtrang;
    book1->tinhtrang = book2->tinhtrang;
    book2->tinhtrang = tmp3;
}

//sxep sách theo mã số sách tăng dần
void booksortbyid(book &head){
    if(head == NULL || head->next == NULL){
        cout<<"Danh sách sách không cần sắp xếp\n";
        return;
    }
    book current = head;
    while(current != NULL){
        book minpos= current;
        book tmp= current->next;
        while(tmp != NULL){
            if(tmp->masosach <minpos->masosach){
                minpos = tmp;
            }
            tmp = tmp->next;
        }
        if(minpos != current){
            swapinfoBook(current,minpos);
        }
        current = current->next;
    }
    cout<<"Danh sách sách đã được sắp xếp theo mã số tăng dần";
}

// Sắp xếp sách theo tên sách tăng dần
void sortByTitle(book& head) {
    if (!head || !head->next) return;
    for (book i = head; i != nullptr; i = i->next) {
        for (book j = i->next; j != nullptr; j = j->next) {
            if (i->tensach > j->tensach) {
                swapinfoBook(i, j);
            }
        }
    }
}

// Sắp xếp sách theo thể loại, sau đó theo tên sách
void sortByCategoryAndTitle(book& head) {
    if (!head || !head->next) return;
    for (book i = head; i != nullptr; i = i->next) {
        for (book j = i->next; j != nullptr; j = j->next) {
            if (i->theloai > j->theloai || (i->theloai == j->theloai && i->tensach > j->tensach)) {
                swapinfoBook(i, j);
            }
        }
    }
}

// Hàm tạo và xử lý độc giả
reader make_reader(string name, int mssv) {
    reader tmp = new Reader();
    tmp->name_reader = name;
    tmp->mssv = mssv;
    tmp->Next = NULL;
    return tmp;
}

bool reader_isempty(reader R) {
    return R == NULL;
}

void init_reader(reader &R) {
    R = NULL;
}
//thêm người đọc
void addReader(reader &R, string name, int mssv) {
    reader new_reader = make_reader(name, mssv);
    if (R == NULL) {
        R = new_reader;
    } else {
        new_reader->Next = R;
        R = new_reader;
    }
    cout << "Thêm độc giả thành công!\n";
}
//tim kiem thong tin ngươi doc
reader search_reader(reader R, int mssv) {
    while (R != NULL) {
        if (R->mssv == mssv) {
            return R;
        }
        R = R->Next;
    }
    return NULL;
}

void hienthithongtindocgia(reader R) {
    while (R != NULL) {
        cout << "Tên độc giả: " << R->name_reader << endl;
        cout << "MSSV: " << R->mssv << endl;
        R = R->Next;
    }
}

// Quản lý mượn/trả sách
void muon_sach(book &B, reader &R) {
    int mssv;
    string mss;
    cout << "Nhập mã số sinh viên: ";
    cin >> mssv;
    cout << "Nhập mã số sách: ";
    cin >> mss;

    book tmp = searchBook(B, mss);
    if (tmp == NULL) {
        cout << "Không tìm thấy sách!\n";
        return;
    }
    if (tmp->soluong == 0) {
        cout << "Sách đã được mượn hết!\n";
        return;
    }

    reader docgia = search_reader(R, mssv);
    if (docgia == NULL) {
        cout << "Không tìm thấy độc giả!\n";
        return;
    }

    tmp->soluong -= 1;       // Giảm số lượng sách
    tmp->tinhtrang = true;   // Đánh dấu sách là "đang được mượn"
    tmp->nguoidoc = docgia;  // Gắn thông tin người mượn vào sách
    cout << "Mượn sách thành công!\n";
}

void tra_sach(book &B, reader R) {
    string mss;
    cout << "Nhập mã số sách: ";
    cin >> mss;

    book tmp = searchBook(B, mss);
    if (tmp == NULL) {
        cout << "Không tìm thấy sách!\n";
        return;
    }
    if (!tmp->tinhtrang) {
        cout << "Sách chưa được mượn!\n";
        return;
    }

    tmp->soluong += 1;       // Tăng lại số lượng sách
    tmp->tinhtrang = false;  // Đánh dấu sách là "co san"
    tmp->nguoidoc = NULL;    // Xóa thông tin người mượn
    cout << "Trả sách thành công!\n";
}
//hiển thị tất cả sách
void thongtin_sach(book B) {
    if(B == NULL){
        cout<<"hiện tại thư viện trống!"<<endl;
    }
    while (B != NULL) {
        cout << "Mã số sách: " << B->masosach << endl;
        cout << "Tên sách: " << B->tensach << endl;
        cout << "Tác giả: " << B->tacgia << endl;
        cout << "Nhà xuất bản: " << B->nhaxuatban << endl;
        cout << "Thể loại: " << B->theloai << endl;
        cout << "Số lượng: " << B->soluong << endl;
        cout << "Tình trạng: " << (B->tinhtrang ? "Đang được mượn" : "Có sẵn") << endl;

        if (B->nguoidoc != NULL) {
            cout << "Người đang mượn:\n";
            cout << "\tTên độc giả: " << B->nguoidoc->name_reader << endl;
            cout << "\tMSSV: " << B->nguoidoc->mssv << endl;
        } else {
            cout << "Người mượn: Không có\n";
        }
        cout << "-----------------------------\n";
        B = B->next;
    }
}
//hiển thị sách theo yêu cầu
void displayBooksFiltered( book head, string& key, int kieuloc) {
    bool found = false;
    book temp = head;
    while (temp) {
        if ((kieuloc == 1 && temp->tensach == key) ||
            (kieuloc == 2 && temp->theloai == key)) {
            cout << "Mã sách: " << temp->masosach << "\n"
                 << "Tên sách: " << temp->tensach << "\n"
                 << "Tác giả: " << temp->tacgia << "\n"
                 << "Nhà xuất bản: " << temp->nhaxuatban << "\n"
                 << "Thể loại: " << temp->theloai << "\n"
                 << "Số lượng: " << temp->soluong << "\n"
                 << "Tình trạng: " << (temp->tinhtrang ? "Đang mượn" : "Sẵn có") << "\n\n";
            found = true;
        }
        if (head->nguoidoc != NULL) {
            cout << "Người đang mượn:\n";
            cout << "\tTên độc giả: " << head->nguoidoc->name_reader << endl;
            cout << "\tMSSV: " << head->nguoidoc->mssv << endl;
        } else {
            cout << "Người mượn: Không có\n";
        }
        cout << "-----------------------------\n";
        temp = temp->next;
    }
    if (!found) cout << "Không tìm thấy sách phù hợp.\n";
}

void menu() {
    cout << "\n======== MENU ========\n";
    cout << "1. Thêm sách\n";
    cout << "2. Cập nhật thông tin sách\n";
    cout << "3. Tìm kiếm sách\n";
    cout << "4. Xóa sách\n";
    cout << "5. Sắp xếp sách\n";
    cout << "6. Thêm độc giả\n";
    cout << "7. Hiển thị thông tin độc giả\n";
    cout << "8. Mượn sách\n";
    cout << "9. Trả sách\n";
    cout << "10. Hiển thị danh sách sách\n";
    cout << "11. Lưu dữ liệu vào file\n";
    cout << "12. Tải dữ liệu từ file\n";
    cout << "0. Thoát\n";
    cout << "=======================\n";
    cout << "Nhập lựa chọn: ";
}

void searchMenu(book &BOOK) {
    cout << "\n----- Tìm kiếm sách -----\n";
    cout << "1. Theo mã sách\n";
    cout << "2. Theo tên sách\n";
    cout << "3. Theo thể loại\n";
    cout << "4. Theo tác giả\n";
    cout << "0. Quay lại\n";
    cout << "Lựa chọn của bạn: ";

    int choice;
    cin >> choice;
    cin.ignore();
    string input;
    book result = NULL;

    switch (choice) {
    case 1:
        {cout << "Nhập mã sách: "; getline(cin, input);
        result = searchBook(BOOK, input);
        break;}
    case 2:
        {cout << "Nhập tên sách: "; getline(cin, input);
        result = searchBookbytitle(BOOK, input);
        break;}
    case 3:
        {cout << "Nhập thể loại: "; getline(cin, input);
        result = searchBookbycategory(BOOK, input);
        break;}
    case 4:
        {cout << "Nhập tên tác giả: "; getline(cin, input);
        result = searchBookbyAuthor(BOOK, input);
        break;}
    case 0:
        return;
    default:
        {cout << "Lựa chọn không hợp lệ!\n";
        return;}
    }

    if (result) {
    //    cout << "Mã số sách: " << result->masosach << endl;
    //     cout << "Tên sách: " << result->tensach << endl;
    //     cout << "Tác giả: " << result->tacgia << endl;
    //     cout << "Nhà xuất bản: " << result->nhaxuatban << endl;
    //     cout << "Thể loại: " << result->theloai << endl;
    //     cout << "Số lượng: " << result->soluong << endl;
    } else {
        cout << "Không có thông tin để hiển thị." << endl;
    }
}

void sortMenu(book &BOOK) {
    cout << "\n----- Sắp xếp sách -----\n";
    cout << "1. Theo mã số sách\n";
    cout << "2. Theo tên sách\n";
    cout << "3. Theo thể loại và tên sách\n";
    cout << "0. Quay lại\n";
    cout << "=======================\n";
    cout << "Lựa chọn của bạn: ";

    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        booksortbyid(BOOK);
        break;
    case 2:
        sortByTitle(BOOK);
        break;
    case 3:
        sortByCategoryAndTitle(BOOK);
        break;
    case 0:
        return;
    default:
        cout << "Lựa chọn không hợp lệ!\n";
    }
}

void displayMenu(book &BOOK) {
    cout << "\n----- Hiển thị sách -----\n";
    cout << "1. Hiển thị tất cả sách\n";
    cout << "2. Lọc theo tên sách\n";
    cout << "3. Lọc theo thể loại\n";
    cout << "0. Quay lại\n";
    cout << "=======================\n";
    cout << "Lựa chọn của bạn: ";

    int choice;
    cin >> choice;
    
    cin.ignore();
    string input;

    switch (choice) {
    case 1:
        thongtin_sach(BOOK);
        break;
    case 2:
        cout << "Nhập tên sách: "; getline(cin, input);
        displayBooksFiltered(BOOK, input, 1);
        break;
    case 3:
        cout << "Nhập thể loại: "; getline(cin, input);
        displayBooksFiltered(BOOK, input, 2);
        break;
    case 0:
        return;
    default:
        cout << "Lựa chọn không hợp lệ!\n";
    }
}
void saveToFile(book BOOK, const string &filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Không thể mở file để ghi!\n";
        return;
    }
    book temp = BOOK;
    while (temp != NULL) {
        file << temp->masosach << "|"
             << temp->tensach << "|"
             << temp->tacgia << "|"
             << temp->nhaxuatban << "|"
             << temp->theloai << "|"
             << temp->soluong << "\n";
        temp = temp->next;
    }
    file.close();
    cout << "Dữ liệu đã được lưu vào file " << filename << ".\n";
}

void loadFromFile(book &BOOK, const string &filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Không thể mở file để đọc!\n";
        return;
    }
    string line, masosach, tensach, tacgia, nxb, theloai;
    int soluong;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, masosach, '|');
        getline(ss, tensach, '|');
        getline(ss, tacgia, '|');
        getline(ss, nxb, '|');
        getline(ss, theloai, '|');
        ss >> soluong;
        insertBook(BOOK, tensach, tacgia, nxb, theloai, masosach, soluong);
    }
    file.close();
    cout << "Dữ liệu đã được tải từ file " << filename << ".\n";
}


int main() {
    book BOOK = NULL;
    reader READER = NULL;
    int choice;

    insertBook(BOOK,"ltm", "nhp", "bkhn", "vatly", "001", 100);
    insertBook(BOOK,"tdt", "hpc"," bkhn", "vatly", "002", 100);
    insertBook(BOOK,"vldt", "ph","bkhn", "toanhoc", "003", 100);
    cout<<"them thanh cong";
    do {
        menu();
        cin >> choice;
        cin.ignore(); // Clear buffer

        switch (choice) {
        case 1: {
            string ten, tacgia, nxb, theloai, masosach;
            int soluong;
            cout << "Nhập tên sách: "; getline(cin, ten);
            cout << "Nhập tác giả: "; getline(cin, tacgia);
            cout << "Nhập nhà xuất bản: "; getline(cin, nxb);
            cout << "Nhập thể loại: "; getline(cin, theloai);
            cout << "Nhập mã sách: "; getline(cin, masosach);
            cout << "Nhập số lượng: "; cin >> soluong;
            insertBook(BOOK, ten, tacgia, nxb, theloai, masosach, soluong);
            break;
        }
        case 2:
        {
            // display Library
            updateBook(BOOK);
            break;
        }
            updateBook(BOOK);
            break;
        case 3:
            searchMenu(BOOK);
            break;
        case 4: {
            string id;
            cout << "Nhập mã sách cần xóa: ";
            getline(cin, id);
            deleteBook(BOOK, id);
            break;
        }
        case 5:
            sortMenu(BOOK);
            break;
        case 6: {
            string name;
            int mssv;
            cout << "Nhập tên độc giả: "; getline(cin, name);
            cout << "Nhập MSSV: "; cin >> mssv;
            addReader(READER, name, mssv);
            break;
        }
        case 7:
            hienthithongtindocgia(READER);
            break;
        case 8:
            muon_sach(BOOK, READER);
            break;
        case 9:
            tra_sach(BOOK, READER);
            break;
        case 10:
            displayMenu(BOOK);
            break;
        case 11:
            saveToFile(BOOK, "books.txt");
            break;
        case 12:
            loadFromFile(BOOK, "books.txt");
            break;
        case 0:
            cout << "Thoát chương trình.\n";
            break;
        default:
            cout << "Lựa chọn không hợp lệ. Thử lại!\n";
        }
    } while (choice != 0);

    return 0;
}

