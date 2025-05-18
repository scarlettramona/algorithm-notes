class GamePlatform 
{
public:
    static double calculateFinalSpeed(double initialSpeed, const std::vector<int>& inclinations) 
    {
        if (inclinations.size() == 0)
                return initialSpeed;
        
        double finalSpeed;
        finalSpeed = initialSpeed;

        for(size_t i = 0; i < inclinations.size(); i++)
        {
            finalSpeed = finalSpeed + static_cast<double>(inclinations[i]);

            if(finalSpeed <= 0)
                return 0;
        }
        
        return finalSpeed;
    }
};