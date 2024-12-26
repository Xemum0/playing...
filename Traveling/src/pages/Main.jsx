import SideBar from "../components/SideBar";
import Map from "../components/Map.jsX";
import styles from './AppLayout.module.css';
function App() {
  return ( 
    <div className={styles.app}>
      <SideBar/>
      <Map/>
    </div>
  );
}

export default App;
