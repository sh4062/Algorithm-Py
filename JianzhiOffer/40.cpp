//数组中只出现一次的数字

class Solution
{
  public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        if (data.size() < 2)
            return;

        int resultExclusiveOR = 0;
        for (int i = 0; i < data.size(); i++)
        {
            resultExclusiveOR ^= data[i];
        }

        unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

        *num1 = *num2 = 0;
        for (int j = 0; j < data.size(); j++)
        {
            if (IsBit1(data[j], indexOf1))
                *num1 ^= data[j];
            else
                *num2 ^= data[j];
        }
    }

    unsigned int FindFirstBitIs1(int num) //找到最右边是1的位
    {
        int indexBit = 0;
        while (((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
        {
            num = num >> 1;
            indexBit++;
        }

        return indexBit;
    }

    bool IsBit1(int num, unsigned int indexBit) //判断在num的二进制中从右边起的indexbit位是不是1
    {
        num = num >> indexBit;
        return (num & 1);
    }
};