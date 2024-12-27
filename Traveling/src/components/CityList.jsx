import CityItem from "./CityItem";
import styles from "./CityList.module.css";
import Spinner from "./Spinner";
import Message from "./Message";
import PropTypes from 'prop-types';


function CityList(props) {
  if (props.isLoading) return <Spinner />;
  if (!props.cities) return <Message message={"add your city to start by clicking on a city in the map"}/>
  return <ul className={styles.cityList}>{props.cities.map((city,index) => <CityItem key={index} city={city}/> )}</ul>;
}
CityList.propTypes = {
  cities:PropTypes.array,
  isLoading: PropTypes.string,
}
export default CityList;
