import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.ptr.IntByReference;
import com.sun.jna.ptr.PointerByReference;

import java.util.Arrays;
import java.util.List;

public interface Anti_collision extends Library{
    public static class LOCATION extends Structure{
        public static class ByReference extends LOCATION implements Structure.ByReference {
            public List<String> getFieldOrder() {
                return Arrays.asList(new String[] { "longitude", "latitude" });
            }
        }

        public int longitude;
        public int latitude;
        public LOCATION(){}
        public LOCATION(Pointer p){
            super(p);
        }
        public List<String> getFieldOrder() {
            return Arrays.asList(new String[] { "longitude", "latitude" });
        }
    }
    public void getSafeDistanceShips(LOCATION.ByReference source,
                                     LOCATION.ByReference dataSet,
                                     int dataSetSize,
                                     int safeDistance,
                                     PointerByReference valsRef,
                                     IntByReference numValsRef);
    public void cleanupStrutArray(Pointer p);

    /////////// 如下为调用入口 ///////////
    /**
     * 需要将C编译的dll 或者so 文件放入Java运行目录。
     */
    Anti_collision LIBRARY = (Anti_collision) Native.loadLibrary("anti-collision", Anti_collision.class);

}
