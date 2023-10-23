public class len {
    public static void main(String[] args)
    {
        String str="MISSISSIPI";
        int freq[] = new int[str.length()];
        char word[] = str.toCharArray();
        for(int i=0;i<str.length();i++)
        {
            freq[i]=1;
            for(int j=i+1;j<str.length();j++)
            {
                if(word[i]==word[j])
                {
                    freq[i]++;
                    word[j]='0';
                }
            }
        }
    }
    
}
