import com.sun.jna.Pointer;
import com.sun.jna.ptr.IntByReference;
import com.sun.jna.ptr.PointerByReference;

public class Test {
    public static void main(String[] args) {

        /* 步骤1：初始化入参 */
        final Anti_collision.LOCATION.ByReference source = new Anti_collision.LOCATION.ByReference();
        source.latitude = 3;
        source.longitude = 1;

        int dataSetSize = 5;
        final Anti_collision.LOCATION.ByReference dataSet = new Anti_collision.LOCATION.ByReference();
        final Anti_collision.LOCATION[] vals = (Anti_collision.LOCATION[])dataSet.toArray(dataSetSize);
        int i;
        for(i=0;i<dataSetSize;i++){
            vals[i].latitude = i+1;
            vals[i].longitude = i+1;
        }

        int safeDistance = 1;

        /* 步骤2：初始化出参 */
        final PointerByReference valsRefPtr = new PointerByReference();
        final IntByReference numValsRef = new IntByReference();

        /*步骤3：调用接口，获取出参*/
        Anti_collision.LIBRARY.getSafeDistanceShips(source, dataSet, dataSetSize, safeDistance,valsRefPtr, numValsRef);

        int numVals = numValsRef.getValue();
        if (numVals == 0) {
            System.out.println("安全距离内船只数为0");
        }
        else {
            // 提取二级指针
            final Pointer pVals = valsRefPtr.getValue();
            // 读取指向LOCATION结构的指针
            final Anti_collision.LOCATION valsRef = new Anti_collision.LOCATION(pVals);
            valsRef.read();
            // Structure.toArray 把数据从c申请的内存空间拷贝到java的LOCATION数组里
            // 注意：如果是特别的数组，这将会很慢
            final Anti_collision.LOCATION[] loc_vals = (Anti_collision.LOCATION[])valsRef.toArray(numVals);

            /* 步骤4：展示获取到的数据结果*/
            System.out.println("安全距离内船只数为："+ numVals + "他们的经纬度是：");
            for (final Anti_collision.LOCATION loc_val:loc_vals){
                System.out.println( "\t(" + loc_val.longitude + "," + loc_val.latitude + ")");
            }

            /* 步骤5：调用c代码，释放内存空间*/
            Anti_collision.LIBRARY.cleanupStrutArray(pVals);
        }
    }
}
