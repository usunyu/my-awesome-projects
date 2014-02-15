package com.sun.spring.web.controllers;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import com.sun.spring.web.dao.Offer;
import com.sun.spring.web.service.OffersService;

@Controller
public class OffersController {
	
	/*
	@RequestMapping("/")
	public ModelAndView showHome() {
		
		ModelAndView mv = new ModelAndView("home");
		
		Map<String, Object> model = mv.getModel();
		
		model.put("name", "<b>River</b>");
		
		return mv;
	}
	*/
	
	private OffersService offersService;
	
	@Autowired
	public void setOffersService(OffersService offersService) {
		this.offersService = offersService;
	}

	@RequestMapping("/offers")
	public String showOffers(Model model) {
		
		List<Offer> offers = offersService.getCurrent();
		
		model.addAttribute("offers", offers);
		
		return "offers";
	}
	
	@RequestMapping("/createoffer")
	public String createOffer() {
		
		return "createoffer";
	}
}
