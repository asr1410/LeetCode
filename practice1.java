import java.util.ArrayList;
import java.util.List;

public class practice1 {
    public static void main(String[] args) {
        List<Long> res = new ArrayList<>();
        Long sumLong = (long) 0;
        for (Long long1 : res) {
            sumLong += long1;
        }
        res.add(sumLong);
        sumLong = (long) 0;
        System.out.println(sumLong);
        for (Long long1 : res) {
            if (long1 > 0) {
                sumLong++;
            }
        }
        res.add(sumLong);
        sumLong = (long) 0;
        System.out.println(sumLong);
        for (Long long1 : res) {
            if (long1 == 0) {
                sumLong++;
            }
        }
        res.add(sumLong);
        sumLong = (long) 0;
        System.out.println(sumLong);
        for (int i = 0; i < res.size(); i++) {
            if (i > res.size() - 4) {
                sumLong += res.get(i);
            }
        }
        res.add(sumLong);
        sumLong++;
        System.out.println(sumLong);
    }
}
