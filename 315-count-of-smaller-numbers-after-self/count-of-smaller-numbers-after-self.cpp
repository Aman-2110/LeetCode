#pragma GCC optimize("O3")
#include <iostream>
#include <utility>
#include <vector>

static bool foo_ = std::ios_base::sync_with_stdio(false);
static auto baz_ = std::cin.tie(NULL);

template <typename T>
class treap {
    template <typename U = T>
    class treap_node {
        U val;
        size_t priority;
        size_t _subtree_size;
        treap_node<U>* left_child;
        treap_node<U>* right_child;

        public:
            treap_node(U val);
            static size_t size(treap_node<U>*);
            void clear();
            treap_node<U>* merge(treap_node<U>*);
            std::pair<treap_node<U>*, treap_node<U>*> split(size_t);
            void fill_array(std::vector<U>&);
            U atIndex(size_t);
            static size_t indexOf(treap_node<U>*, U);
            static size_t lower_bound(treap_node<U>*, U);
            static size_t count(treap_node<U>*, U);
    };

    treap_node<T>* root;
    treap<T>* merge(treap<T>*);
    std::pair<treap<T>*, treap<T>*> split(size_t);

    public:
        treap();
        treap(treap_node<T>*);
        bool empty();
        size_t size();
        void clear();
        void clone_root(treap_node<T>*&);
        treap_node<T>* merge_right_of(treap_node<T>*);
        size_t insert(T);
        bool erase(size_t);
        size_t indexOf(T);
        T atIndex(size_t);
        bool erase(size_t, size_t);
        treap<T>* slice(size_t, size_t);
        size_t lower_bound(T);
        size_t upper_bound(T);
        size_t count(T);
        std::vector<T> to_array();
};

template <typename T>
treap<T>::treap() {
    root = nullptr;
}

template <typename T>
treap<T>::treap(treap_node<T>* node) {
    root = node;
}

template <typename T>
bool treap<T>::empty() {
    return size() == 0;
}

template <typename T>
size_t treap<T>::size() {
    return treap_node<T>::size(root);
}

template <typename T>
void treap<T>::clear() {
    if (root == nullptr) {
        return;
    }

    root->clear();
    root = nullptr;
}

template <typename T>
void treap<T>::clone_root(treap_node<T>*& root) {
    root = this->root;
}

template <typename T>
size_t treap<T>::insert(T val) {
    if (empty()) {
        root = new treap_node<T>(val);
    } else {
        size_t lb = lower_bound(val);
        std::pair<treap<T>*, treap<T>*> treaps = split(lb);
        treap<T>* temp = new treap();
        temp->insert(val);
        treaps.first = treaps.first->merge(temp);
        treaps.first->merge(treaps.second)->clone_root(root);
    }

    return indexOf(val);
}

template <typename T>
bool treap<T>::erase(size_t index) {
    return erase(index, index);
}

template <typename T>
size_t treap<T>::indexOf(T val) {
    return treap_node<T>::indexOf(root, val);
}

template <typename T>
T treap<T>::atIndex(size_t index) {
    if (index >= size()) {
        return T();
    }

    return root->atIndex(index);
}

template <typename T>
treap<T>* treap<T>::merge(treap<T>* other) {
    if (other) {
        root = other->merge_right_of(root);
    }
    return this;
}

template <typename T>
typename treap<T>::template treap_node<T>* treap<T>::merge_right_of(treap_node<T>* node) {
    if (node) {
        return node->merge(root);
    }

    return root;
}

template <typename T>
std::pair<treap<T>*, treap<T>*> treap<T>::split(size_t index) {
    std::pair<treap_node<T>*, treap_node<T>*> roots = root->split(index);
    return {new treap(roots.first), new treap(roots.second)};
}

template <typename T>
bool treap<T>::erase(size_t first, size_t last) {
    if (last < first || last >= size()) {
        return false;
    }

    std::pair<treap<T>*, treap<T>*> treaps = split(first);
    std::pair<treap<T>*, treap<T>*> temp = treaps.second->split(last - first + 1);
    temp.first->clear();
    this = treaps.first->merge(temp.second);
    return true;
}

template <typename T>
treap<T>* treap<T>::slice(size_t first, size_t last) {
    if (last < first || last >= size()) {
        return nullptr;
    }

    std::pair<treap<T>*, treap<T>*> treaps = split(first);
    std::pair<treap<T>*, treap<T>*> temp = treaps.second->split(last - first + 1);
    treaps.first->clear();
    temp.second->clear();
    return temp.first;
}

template <typename T>
size_t treap<T>::lower_bound(T val) {
    // std::cerr << val << " LB: " << 0 << std::endl;
    return treap_node<T>::lower_bound(root, val);
}

template <typename T>
size_t treap<T>::upper_bound(T val) {
    return lower_bound(val) + count(val);
}

template <typename T>
size_t treap<T>::count(T val) {
    // std::cerr << val << " C: " << 0 << std::endl;
    return treap_node<T>::count(root, val);
}

template <typename T>
std::vector<T> treap<T>::to_array() {
    std::vector<T> arr;
    if (empty()) {
        return arr;
    }

    root->fill_array(arr);
    return arr;
}

template <typename T>
template <typename U>
treap<T>::treap_node<U>::treap_node(U val) {
    this->val = val;
    _subtree_size = 1;
    priority = rand();
    left_child = right_child = nullptr;
}

template <typename T>
template <typename U>
void treap<T>::treap_node<U>::clear() {
    if (left_child) {
        left_child->clear();
    }
    if (right_child) {
        right_child->clear();
    }
    free(this);
}

template <typename T>
template <typename U>
void treap<T>::treap_node<U>::fill_array(std::vector<U>& arr) {
    if (left_child != nullptr) {
        left_child->fill_array(arr);
    }

    arr.push_back(val);

    if (right_child != nullptr) {
        right_child->fill_array(arr);
    }
}

template <typename T>
template <typename U>
size_t treap<T>::treap_node<U>::size(treap_node<U>* node) {
    if (node) {
        return node->_subtree_size;
    }
    return 0;
}

template <typename T>
template <typename U>
U treap<T>::treap_node<U>::atIndex(size_t index) {
    int left_size = size(left_child);
    if (index < left_size) {
        return left_child->atIndex(index);
    } else if (index == left_size) {
        return val;
    } else {
        return right_child->atIndex(index - left_size - 1);
    }
}

template <typename T>
template <typename U>
size_t treap<T>::treap_node<U>::indexOf(treap_node<U>* node, U val) {
    if (node) {
        if (node->val < val) {
            int right_index = indexOf(node->right_child, val);
            if (right_index != -1) {
                return size(node->left_child) + 1 + right_index;
            }
        } else if (node->val == val) {
            int left_index = indexOf(node->left_child, val);
            if (left_index != -1) {
                return left_index;
            } else {
                return size(node->left_child);
            }
        } else {
            return indexOf(node->left_child, val);
        }
    }

    return -1;
}

template <typename T>
template <typename U>
size_t treap<T>::treap_node<U>::lower_bound(treap_node<U>* node, U val) {
    if (node) {
        if (node->val < val) {
            return size(node->left_child) + 1 + lower_bound(node->right_child, val);
        } else {
            return lower_bound(node->left_child, val);
        }
    }

    return 0;
}

template <typename T>
template <typename U>
size_t treap<T>::treap_node<U>::count(treap_node<U>* node, U val) {
    if (node) {
        if (node->val < val) {
            return count(node->right_child, val);
        } else if (node->val == val) {
            size_t curr_count = 1;
            if (node->left_child != nullptr && node->left_child->val == val) {
                curr_count += count(node->left_child, val);
            }
            if (node->right_child != nullptr && node->right_child->val == val) {
                curr_count += count(node->right_child, val);
            }
            return curr_count;
        } else {
            return count(node->left_child, val);
        }
    }

    return 0;
}

template <typename T>
template <typename U>
typename treap<T>::template treap_node<U>* treap<T>::treap_node<U>::merge(treap_node<U>* right) {
    if (right) {
        int left_priority = priority;
        int right_priority = right->priority;

        if (left_priority > right_priority) {
            if (right_child) {
                right_child = right_child->merge(right);
                _subtree_size = size(left_child) + 1 + size(right_child);
                return this;
            }

            right_child = right;
            _subtree_size = size(left_child) + 1 + size(right_child);
            return this;
        }

        right->left_child = this->merge(right->left_child);
        right->_subtree_size = size(right->left_child) + 1 + size(right->right_child);
        return right;
    }

    return this;
}

template <typename T>
template <typename U>
std::pair<typename treap<T>::template treap_node<U>*, typename treap<T>::template treap_node<U>*> treap<T>::treap_node<U>::split(size_t index) {
    std::pair<treap_node<T>*, treap_node<T>*> roots;
    roots.first = roots.second = nullptr;

    size_t curr_index = size(left_child);
    if (curr_index < index) {
        roots.first = this;
        if (right_child) {
            std::pair<treap_node<T>*, treap_node<T>*> next_roots = right_child->split(index - curr_index - 1);
            right_child = next_roots.first;
            _subtree_size = size(left_child) + 1 + size(right_child);
            roots.second = next_roots.second;
        }
    } else {
        roots.second = this;
        if (left_child) {
            std::pair<treap_node<T>*, treap_node<T>*> next_roots = left_child->split(index);
            left_child = next_roots.second;
            _subtree_size = size(left_child) + 1 + size(right_child);
            roots.first = next_roots.first;
        }
    }

    return roots;
}

using namespace std;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        srand(time(NULL));
        treap<int>* ordered_set = new treap<int>();
        std::vector<int> count(nums.size());

        for (int i = nums.size() - 1; i >= 0; i--) {
            count[i] = ordered_set->lower_bound(nums[i]);
            ordered_set->insert(nums[i]);
        }

        return count;
    }
};