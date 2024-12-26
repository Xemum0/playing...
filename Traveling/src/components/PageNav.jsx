import { Link } from "react-router-dom";

function PageNav() {
  return (
    <nav>
      <ul>
        <li>
          <Link to={"/"}>Home</Link>
        </li>
        <li>
          <Link to={"/Product"}>Product</Link>
        </li>
        <li>
          <Link to={"/Pricing"}>Pricing</Link>
        </li>
      </ul>
    </nav>
  );
}

export default PageNav;
