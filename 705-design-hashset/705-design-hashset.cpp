class MyHashSet
{
    unordered_map<int, bool> mp;

public:
    MyHashSet()
    {
    }

    void add(int key)
    {
        mp[key] = true;
    }

    void remove(int key)
    {
        mp[key] = false;
    }

    bool contains(int key)
    {
        if (mp[key])
            return true;
        return false;
    }
};