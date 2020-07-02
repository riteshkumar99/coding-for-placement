class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = ((hour == 12) ? 0 : hour) * 30 + minutes/2.0;
        double minutesAngle = minutes * 6.0;
        double diff = abs(hourAngle - minutesAngle);
        return min(diff, 360 - diff);
    }
};
