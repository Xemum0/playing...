import { BrowserRouter, Routes, Route } from "react-router-dom";
import Product from "./pages/Product";
import Home from "./pages/Home";
import Pricing from "./pages/Pricing";
import PageNotFound from "./pages/PageNotFound";
function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/product" element={<Product />} />
        <Route path="/Pricing" element={<Pricing />} />
        <Route path="*" element= {<PageNotFound/>} />
      </Routes>
    </BrowserRouter>
  );
}

export default App;
