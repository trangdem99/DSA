// Balance Multiway Tree code by N.T.Lợi. Thanks :>
#include <iostream>
using namespace std;

struct BTree {
    int* key;   // mảng các dữ liệu
    int t;      // mức độ tối thiểu( xác định phạm vi cho số khóa)
    BTree** c;  // mảng các con trỏ con
    int n;      // số khóa hiện tại
    bool leaf;  // true là left, và ngược lại
};

// tạo node trong cây
BTree* creatTree(int t, bool leaf) {
    BTree* temp = new BTree;

    // gán t mức độ tối thiểu và leaf
    temp->t = t;
    temp->leaf = leaf;

    //tạo mảng choa các kí tự và cũng như các node
    temp->key = new int[2 * t - 1];
    temp->c = new BTree * [2 * t];

    temp->n = 0;  // chưa có giá trị
    return temp;
}

// in cây
void print(BTree* root) {
    int i;
    for (i = 0; i < root->n; i++) {
        // if là lá thì chúng ta in ra giá trị của key[i]
        // còn nếu ko thì chúng ta đệ quy xún cây con
        if (root->leaf == false)
            print(root->c[i]);
        cout << "  " << root->key[i];
    }
    // in cây con bắt nguồn từ cuối cùng
    if (root->leaf == false)
        print(root->c[i]);
}

// tìm kiếm trong cây
BTree* search(BTree* root, int k) {
    // tìm khóa đầu tiền lớn hơn hoặc bằng k
    int i = 0;
    while (i < root->n && k > root->key[i])
        i++;

    // nếu mà đúng thì trả về nút này
    if (root->key[i] == k)
        return root;
    // nếu mà không pk thì và là node leaf thì NULL
    if (root->leaf == true)
        return NULL;

    // đi đến node tiếp theo
    return search(root->c[i], k);
}

// hàm tách con y của node này
// y là phải đầy khi hàm đc gọi
void splitChild(BTree* current_node, int i, BTree* y) {
    // tạo một node mới để lưu trử (t-1)key
    // của y
    BTree* temp = creatTree(y->t, y->leaf);
    temp->n = current_node->t - 1;

    // sao chép khóa (t-1) cuối cùng của y sang temp
    for (int j = 0; j < current_node->t - 1; j++)
        temp->key[j] = y->key[j + current_node->t];

    // sao chép con t cuois cùng của y vào trong temp
    if (y->leaf == false) {
        for (int j = 0; j < current_node->t; j++)
            temp->c[j] = y->c[j + current_node->t];
    }

    // giảm số lương của khóa trong y
    y->n = current_node->t - 1;

    // vì nút này có một nút còn nên tạo không gian mới
    for (int j = current_node->n; j >= i + 1; j--)
        current_node->c[j + 1] = current_node->c[j];

    current_node->c[i + 1] = temp;

    // Vì nút này sẽ có một nút con mới,
    // tạo không gian của con mới
    for (int j = current_node->n - 1; j >= i; j--)
        current_node->key[j + 1] = current_node->key[j];

    // sao chép khóa ở giữa của y sang node hiện tại
    current_node->key[i] = y->key[current_node->t - 1];

    // số lượng khóa tăng dần trong nút hiện tại
    current_node->n = current_node->n + 1;
}

// chèn khóa vào nút giải định nút chưa đầy
void insertNoFull(BTree* currentNode, int k) {
    // Khởi tạo chỉ mục dưới dạng chỉ mục của phần tử ngoài cùng bên phải
    int i = currentNode->n - 1;

    // nếu là leaf thì
    if (currentNode->leaf == true) {
        // vòng lặp sẻ thực hiện 2 điều
        // a. là tìm vị trí mà khóa sẻ đc chèn
        // b. là di chuyển các khóa lớn hơn lên phía trước
        while (i >= 0 && currentNode->key[i] > k) {
            currentNode->key[i + 1] = currentNode->key[i];
            i--;
        }

        // thêm vào vị trí
        currentNode->key[i + 1] = k;
        currentNode->n = currentNode->n + 1;
    }
    else {
        // nếu node đóa không phải là leaf thì
        //Tìm con sẽ có chìa khóa mới
        while (i >= 0 && currentNode->key[i] > k)
            i--;

        // xem coi đầy chưa
        if (currentNode->c[i + 1]->n == 2 * currentNode->t - 1) {
            // nếu đầy thì gọi hàm split để chia đôi
            splitChild(currentNode, i + 1, currentNode->c[i + 1]);

            // Sau khi tách, khóa giữa của C [i] đi lên và
            // C [i] được tách thành hai. Xem cái nào trong hai cái
            // sẽ có khóa mới
            if (currentNode->key[i + 1] < k)
                i++;
        }
        insertNoFull(currentNode->c[i + 1], k);
    }
}

// hàm thêm phần tử vào cây
void insert(BTree*& root, int k, int t /*Minimum degree*/) {
    // nếu mà cây trống
    if (root == NULL) {
        root = creatTree(t, true);
        root->key[0] = k;
        root->n = 1;
    }
    else {  //  không phải root
     //nếu mà root full thì chúng ta phát triển chiều cao cây
        if (root->n == 2 * t - 1) {
            // cấp phát bộ nhớ choa root
            BTree* s = creatTree(t, false);

            // đặt gốc cũ là con gốc mới
            s->c[0] = root;

            //Tách gốc cũ và di chuyển 1 khóa sang gốc mới
            splitChild(s, 0, root);

            // Hiện tại root mới có hai con. Quyết định cái nào trong số
            // hai đứa trẻ sẽ có khóa mới
            int i = 0;
            if (s->key[0] < k)
                i++;
            insertNoFull(s->c[i], k);

            // thay dổi root
            root = s;
        }
        else  //  nếu mà node root chưa đầy thì
            insertNoFull(root, k);
    }
}

// hàm trả về khóa đầu tiền là lớn hơn hoặc bằng k
int findKey(BTree* node, int k) {
    int idx = 0;
    while (idx < node->n && node->key[idx] < k)
        ++idx;
    return idx;
}

void merge(BTree* node, int idx) {
    int t = node->t;
    BTree* child = node->c[idx];
    BTree* sibling = node->c[idx + 1];

    // Kéo một khóa từ nút hiện tại và chèn nó vào (t-1) th
    // vị trí của C [idx]
    child->key[t - 1] = node->key[idx];

    // sao chép các khóa từ C [idx + 1] sang C [idx] ở cuối
    for (int i = 0; i < sibling->n; i++)
        child->key[i + t] = sibling->key[i];

    // sao chép con trỏ child từ  C[idx+1] to C[idx]
    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; i++)
            child->c[i + t] = sibling->c[i];
    }

    // Di chuyển tất cả các khóa sau idx trong nút hiện tại trước một bước -
    // để lấp đầy khoảng trống được tạo bằng cách di chuyển các phím [idx] đến C [idx]
    for (int i = idx + 1; i < node->n; i++)
        node->key[i - 1] = node->key[i];

    // Di chuyển con trỏ con sau (idx + 1) trong nút hiện tại một // bước trước
    for (int i = idx + 2; i <= node->n; i++)
        node->c[i - 1] = node->c[i];

    // Cập nhật số khóa của nút con và nút hiện tại
    child->n += sibling->n + 1;
    node->n--;

    // Giải phóng bộ nhớ bị chiếm dụng bởi anh chị em
    delete (sibling);
    return;
}

// Một hàm mượn khóa từ C [idx + 1] và đặt
// nó trong C [idx]
void borrowFromNext(BTree* node, int idx) {
    BTree* child = node->c[idx];
    BTree* sibling = node->c[idx + 1];

    // các khóa [idx] được chèn làm khóa cuối cùng trong C [idx]
    child->key[(child->n)] = node->key[idx];

    // Đứa con đầu tiên của anh chị em ruột được chèn làm đứa con cuối cùng
    // thành C [idx]
    if (!(child->leaf))
        child->c[(child->n) + 1] = sibling->c[0];

    // Khóa đầu tiên từ anh chị em được chèn vào các khóa [idx]
    node->key[idx] = sibling->key[0];

    //chuyển tất cả khóa trong sibling chậm hơn một bước
    for (int i = 1; i < sibling->n; i++)
        sibling->key[i - 1] = sibling->key[i];

    // Di chuyển con trỏ con chậm hơn một bước
    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; ++i)
            sibling->c[i - 1] = sibling->c[i];
    }

    // Tăng và giảm số lượng khóa của C [idx] và C [idx + 1]
    // tương ứng
    child->n += 1;
    sibling->n -= 1;

    return;
}

void borrowFromPrev(BTree* node, int idx) {
    BTree* child = node->c[idx];
    BTree* sibling = node->c[idx - 1];

    // Khóa cuối cùng từ C [idx-1] chuyển đến khóa mẹ và khóa [idx-1]
    // từ cha được chèn làm khóa đầu tiên trong C [idx]. Vì vậy, những mất mát
    // anh chị em một khóa và con nhận được một khóa

    // Di chuyển tất cả khóa trong C [idx] trước một bước
    for (int i = child->n - 1; i >= 0; i--)
        child->key[i + 1] = child->key[i];

    // Nếu C [idx] không phải là một lá, hãy di chuyển tất cả các con trỏ con của nó trước một bước
    if (!child->leaf) {
        for (int i = child->n; i >= 0; --i)
            child->c[i + 1] = child->c[i];
    }

    // Đặt khóa đầu tiên của con bằng các khóa [idx-1] từ nút hiện tại
    child->key[0] = node->key[idx - 1];

    // Chuyển con cuối cùng của anh chị em thành con đầu tiên của C [idx]
    if (!child->leaf)
        child->c[0] = sibling->c[sibling->n];

    // Di chuyển khóa từ khóa anh chị em sang khóa cha mẹ
    // Điều này làm giảm số lượng khóa trong anh chị em
    node->key[idx - 1] = sibling->key[sibling->n - 1];

    child->n += 1;
    sibling->n -= 1;

    return;
}

//hàm điền con C [idx] có ít hơn t-1 khóa
void fill(BTree* node, int idx) {
    int t = node->t;
    // Nếu con trước (C [idx-1]) có nhiều hơn t-1 khóa, hãy mượn một khóa
    // từ đứa trẻ đó
    if (idx != 0 && node->c[idx - 1]->n >= t)
        borrowFromPrev(node, idx);

    // Nếu con tiếp theo (C [idx + 1]) có nhiều hơn t-1 khóa, hãy mượn một khóa
    // từ đứa trẻ đó
    else if (idx != node->n && node->c[idx + 1]->n >= t)
        borrowFromNext(node, idx);

    // Hợp nhất C [idx] với anh chị em của nó
    // Nếu C [idx] là con cuối cùng, hãy hợp nhất nó với anh chị em trước của nó
    // Nếu không thì hợp nhất nó với anh chị em tiếp theo của nó

    else {
        if (idx != node->n)
            merge(node, idx);
        else
            merge(node, idx - 1);
    }
    return;
}

int getSucc(BTree* node, int idx) {
    // Tiếp tục di chuyển nút ngoài cùng bên trái bắt đầu từ C [idx + 1] cho đến khi chúng ta đến một lá
    BTree* cur = node->c[idx + 1];
    while (!cur->leaf)
        cur = cur->c[0];

    return cur->key[0];
}
// tương tự như trên
int getPred(BTree* node, int idx) {
    BTree* cur = node->c[idx];
    while (!cur->leaf)
        cur = cur->c[cur->n];

    return cur->key[cur->n - 1];
}

void removeFromNonLeaf(BTree* node, int idx) {
    int k = node->key[idx];

    // Nếu con đứng trước k (C [idx]) có ít nhất t khóa,
    // tìm tiền thân 'trước' của k trong cây con có gốc tại
    // C [idx]. Thay thế k bằng trước. Xóa đệ quy trước
    // trong C [idx]
    if (node->c[idx]->n >= node->t) {
        int pred = getPred(node, idx);
        node->key[idx] = pred;
        removee(node->c[idx], pred);
    }

    // Nếu con C [idx] có ít hơn t khóa, hãy kiểm tra C [idx + 1].
    // Nếu C [idx + 1] có ít nhất t khóa, hãy tìm 'succ' kế nhiệm của k trong
    // cây con bắt nguồn từ C [idx + 1] // Thay k bằng succ
    // Xóa đệ quy succ trong C [idx + 1]
    else if (node->c[idx + 1]->n >= node->t) {
        int succ = getSucc(node, idx);
        node->key[idx] = succ;
        removee(node->c[idx + 1], succ);
    }

    // Nếu cả C [idx] và C [idx + 1] có ít hơn t khóa, hãy hợp nhất k và tất cả C [idx + 1]
    // thành C [idx]
    // Bây giờ C [idx] chứa 2t-1 khóa
    // Giải phóng C [idx + 1] và xóa đệ quy k khỏi C [idx]
    else {
        merge(node, idx);
        removee(node->c[idx], k);
    }
    return;
}

void removeFromLeaf(BTree* node, int idx) {
    // Di chuyển tất cả các phím sau chiến tranh lùi một nơi idx-th pos
    for (int i = idx + 1; i < node->n; i++)
        node->key[i - 1] = node->key[i];
    // Giảm số lượng phím
    node->n--;
    return;
}

void removee(BTree* node, int k) {
    int idx = findKey(node, k);

    // khóa cần xóa có trong nút này
    if (idx < node->n && node->key[idx] == k) {
        if (node->leaf)
            removeFromLeaf(node, idx);
        else
            removeFromNonLeaf(node, idx);
    }
    else {
        // Nếu nút này là nút lá, thì khóa không có trong cây
        if (node->leaf) {
            cout << "khoa " << k << " ko cos ton tai" << endl;
            return;
        }

        bool flag = ((idx == node->n) ? true : false);

        if (node->c[idx]->n < node->t)
            fill(node, idx);

        if (flag && idx > node->n)
            removee(node->c[idx - 1], k);
        else
            removee(node->c[idx], k);
    }
    return;
}

void remove(BTree*& root, int k) {
    if (!root) {
        cout << "cay trong" << endl;
    }

    removee(root, k);

    // Nếu nút gốc có 0 khóa, hãy đặt nút con đầu tiên của nó làm nút gốc mới
    // nếu nó có con, nếu không thì đặt root là NULL
    if (root->n == 0) {
        BTree* temp = root;
        if (root->leaf)
            root = NULL;
        else
            root = root->c[0];

        delete temp;
    }
    return;
}


int findMin(BTree* root)
{
    if (root == NULL)
        return -1111;
    else {
        if (root->leaf != false)
            return root->key[0];
        else {
            return findMin(root->c[0]);
        }
    }
}
