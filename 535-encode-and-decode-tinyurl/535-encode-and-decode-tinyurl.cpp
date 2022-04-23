class Solution
{
public:
    unordered_map<string, string> m;
    int num = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        num++;
        string addon = to_string(num);
        string ans = "http://tinyurl.com/";
        ans += (string)addon;
        m[ans] = longUrl;
        return ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return m[shortUrl];
    }
};